/*
 * base.cc
 *
 *  Created on: Dec 20, 2014
 *      Author: orhangazi44
 *
 *      LGPL
 *
 */

#include "base.h"

Define_Module(Base);

void Base::initialize()
{
    mainModule = getModuleByPath("LeachBasic");
    p = mainModule->par("p").doubleValue();
    numNodes = mainModule->par("numNodes");
    clusterMaxMember = (int)(1 / p);
    numClusters = (numNodes / clusterMaxMember);
    numberOfLivingNodes = numNodes;
    receivedRoundCount = 0;
    totalExpendedEnergy = .0;
    nodeDeaths = new bool[ numNodes ];
    nodeBatteries = new double[ numNodes ];
    posXs = new int [numNodes];
    posYs = new int [numNodes];
    double ndbt = mainModule->par("nodeBatteries");

    for(int i = 0; i < numNodes; i++)
    {
        nodeDeaths[i] = false; // Buna sonra bak
        nodeBatteries[i] = ndbt;
        posXs[i] = 0;
        posYs[i] = 0;
    }

    WATCH(numberOfLivingNodes);
    WATCH(receivedRoundCount);

    char* str = new char[16];
    xPosition = mainModule->par("bazX");
    yPosition = mainModule->par("bazY");
    sprintf(str, "(%d, %d)", xPosition, yPosition);
    getDisplayString().setTagArg("t", 0, str);
    getDisplayString().setTagArg("p", 0, xPosition);
    getDisplayString().setTagArg("p", 1, yPosition);

    totalEnergyVector.setName("Total Energy Vector");
    numberOfLivingNodesVector.setName("Number Of Living Nodes Vector");
    receivedRoundCountVector.setName("Received Round Count Vector");
    expendedEnergiesForRoundsVector.setName("Expended Energies For Rounds Vector");

    totalEnergyVector.record(totalExpendedEnergy);
    numberOfLivingNodesVector.record(numberOfLivingNodes);
    receivedRoundCountVector.record(receivedRoundCount);
    expendedEnergiesForRoundsVector.record(0.0);

    algorithm = mainModule->par("algorithm");
    if (algorithm != LEACH && algorithm != IMPLEACH) // leach ve impleach de Nb hesaplama işlemleri başlatılmayavak
    {
        cMessage * msg1 = new cMessage("xyToNodes");
        simtime_t stt1 = 0.2;
        scheduleAt(stt1, msg1);
    }

    cMessage * msg1 = new cMessage("recordEnergy");
    simtime_t stt1 = 0.1;
    scheduleAt(stt1, msg1);
}

void Base::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(), "recordEnergy") == 0 )
    {
        if(noEnergy)
        {
            EV << "NO MORE INFORMATION, SIMULATION IS STOPPING!!!!!!!!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
            return;
        }
        EV << "RECORDING =======================================XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  " << expendedEnergyForRound << "    XXXXXXXXXX\n";

        // Yaşayan düğümleri say
//        int count = 0;
//        for(int i = 0; i < numNodes; i++)
//        {
//            if (nodeDeaths[i]) count++;
//        }

        expendedEnergiesForRoundsVector.record(expendedEnergyForRound);
        // expendedEnergyForRound = .0;
        noEnergy = true;
        scheduleAt(simTime()+4, msg);
        return;
    }
    if(strcmp(msg->getName(), "xyToNodes") == 0 )
    {
        for(int i = 0; i < numNodes; i++)
        {
            char *c = new char[64];
            sprintf(c, "%d:", posXs[i]);
            posInfoMessageString.append(c);
            sprintf(c, "%d", posYs[i]);
            posInfoMessageString.append(c);
            posInfoMessageString.append("_"); // ilgili düğümün bilgisi stringe eklenince bitirmek için '_' koydum, sonra split edeceğim.
        }

        EV << "POSXS[" << numNodes << "] = {";
        for(int i = 0; i < numNodes; i++)
        {
            EV << posXs[i] << ",";
        }
        EV << "};\n";

        EV << "POSYS[" << numNodes << "] = {";
        for(int i = 0; i < numNodes; i++)
        {
            EV << posYs[i] << ",";
        }
        EV << "};";

        for(int i = 0; i < numNodes; i++)
        {
            head2baseMsg * msg0 = new head2baseMsg("info");
            msg0->setMes(posInfoMessageString.c_str());
            msg0->setKind(2);
            char *chr = new char[32];
            sprintf(chr, "LeachBasic.nd[%d]",i);
            sendDirect(msg0, getModuleByPath(chr), "in");
        }
        return;
    }

    head2baseMsg * msg1 = check_and_cast<head2baseMsg *>(msg);

    if(strcmp(msg->getName(), "die") == 0 && nodeDeaths[msg1->getSource()] == false)
    {
        nodeDeaths[msg1->getSource()] = true;
        numberOfLivingNodes--;
        numberOfLivingNodesVector.record(numberOfLivingNodes);
        return;
    }

    if(strcmp(msg->getName(), "myXY") == 0 )
    {
        int source = msg1->getSource();
        posXs[source] = msg1->getPosX();
        posYs[source] = msg1->getPosY();
    }

    if(strcmp(msg->getName(), "myBattery") == 0 )
    {
        noEnergy = false;
        int src = msg1->getSource();
        double olddd = nodeBatteries[src];
        nodeBatteries[src] = msg1->getTotalExpendedEnergy();
        expendedEnergyForRound += (olddd - nodeBatteries[src]);
    }

    if(strcmp(msg1->getName(), "h2bM") == 0)
    { // Message arrived.
        EV << "BASE: Message " << msg->getName() << " arrived from node[" << msg->getSenderModuleId()-2 << "].\n";
        EV << "BASE: RECEIVED DIE COUNT : " << msg1->getDieCount() << " *********************************************************************.\n";
        bubble("ARRIVED");
    }
    delete msg;
}

void Base::finish()
{
    recordScalar("#receivedRoundCount", receivedRoundCount);
    numberOfLivingNodesStats.recordAs("Number of Living Nodes");
}





