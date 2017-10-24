/*
 * base.h
 *
 *  Created on: Jan 1, 2015
 *      Author: orhangazi44
 *
 *      LGPL
 *
 */

#ifndef BASE_H_
#define BASE_H_

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "leach_message_m.h"

static int LEACH = 0;
static int IMPLEACH = 1;
static int CCRP = 2;
static int WSTLEACH = 3;

class Base : public cSimpleModule
{
  private:
    int clusterMaxMember;
    int numNodes;
    int numClusters;
    double p;
    cModule *mainModule;
    int xPosition, yPosition;
    int receivedRoundCount;
    int numberOfLivingNodes;
    int algorithm;
    bool * nodeDeaths;
    bool noEnergy = false;
    double totalExpendedEnergy;
    int * posXs;
    int * posYs;
    double * nodeBatteries;
    double expendedEnergyForRound;
    std::string posInfoMessageString;
    cLongHistogram numberOfLivingNodesStats;
    cLongHistogram receivedRoundCountStats;
    cLongHistogram expendedEnergiesForRoundsStats;
    cOutVector expendedEnergiesForRoundsVector;
    cOutVector numberOfLivingNodesVector;
    cOutVector receivedRoundCountVector;
    cOutVector totalEnergyVector;

  protected:
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
};

#endif /* BASE_H_ */









