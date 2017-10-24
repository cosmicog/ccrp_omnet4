/*
 * node.cc
 *
 *  Created on: Dec 20, 2014
 *      Author: orhangazi44
 *
 *      LGPL
 *
 */

#include "node.h" // Diğer kütüphaneler ve kullandığım adresten bağımsız fonksiyonlar bunda.

Define_Module(Node);

//int POSXS[400] = {163,182,25,183,127,19,55,109,192,193,31,195,192,97,160,28,84,184,159,192,131,7,170,187,136,152,149,78,131,34,141,6,55,9,19,165,139,63,190,6,88,76,153,159,37,98,89,129,142,151,55,136,131,32,23,100,192,68,117,44,151,51,101,140,179,192,109,27,30,51,168,51,163,48,186,70,39,50,123,95,70,166,117,110,184,57,152,151,76,114,15,10,106,156,187,26,114,94,2,67,32,159,62,106,33,120,52,131,138,150,90,16,46,183,30,165,108,200,15,88,21,193,0,155,164,174,16,80,52,160,86,183,36,53,29,27,174,116,110,29,171,125,70,103,80,15,48,24,36,48,83,9,181,189,98,98,67,180,74,22,156,78,48,81,19,26,189,192,115,12,47,70,165,3,8,33,130,147,130,90,109,59,149,37,138,36,74,125,156,16,186,155,97,87,89,61,102,102,164,159,129,76,163,107,70,188,176,110,125,117,41,60,94,46,169,39,45,34,45,87,62,185,86,37,181,196,88,22,51,82,119,52,121,142,44,23,59,64,85,102,17,52,161,5,186,146,98,116,47,92,193,109,104,46,98,125,136,79,73,198,7,177,183,160,19,52,67,136,27,144,21,131,99,156,143,181,179,67,140,39,6,149,100,96,181,122,124,172,161,115,36,48,178,5,98,33,196,143,100,94,11,137,8,14,104,19,164,164,145,30,132,104,195,130,160,91,86,165,16,26,34,78,167,161,12,80,105,83,132,126,58,86,3,197,33,21,74,39,98,68,191,184,10,148,54,84,110,189,83,197,60,140,133,108,140,133,35,25,200,34,6,112,177,134,38,74,92,197,31,171,129,75,38,86,96,24,118,45,77,117,50,58,124,53,165,197,146,69,117,21,182,176,164,52,119,4,85,62,32,35};
//int POSYS[400] = {85,18,120,94,139,140,128,6,13,64,106,131,81,164,144,194,106,65,21,122,156,85,18,53,30,56,88,105,91,175,104,189,128,192,48,135,58,135,139,13,51,45,134,169,69,156,135,1,121,77,184,0,92,85,92,154,64,157,94,7,35,145,95,30,68,122,38,148,48,184,54,153,37,57,18,115,137,109,85,129,130,136,127,189,41,142,47,23,122,90,92,133,154,70,133,83,169,167,51,123,117,108,174,53,63,23,188,129,96,128,109,130,109,144,105,199,43,21,22,12,81,90,73,153,126,155,187,195,38,27,139,18,105,106,173,97,79,134,148,104,69,30,117,52,8,151,48,88,138,72,148,79,137,141,88,3,66,85,54,39,165,86,178,78,154,79,162,151,75,43,158,190,65,134,88,167,154,33,173,198,103,177,118,31,40,81,150,165,158,64,107,18,22,27,136,99,38,99,29,11,170,112,186,140,117,163,176,198,0,173,123,198,106,96,161,45,100,181,115,169,148,117,49,133,16,125,132,146,179,197,154,116,186,116,3,24,173,97,169,42,111,126,6,123,72,9,98,38,24,41,29,38,8,127,56,108,139,100,107,89,24,98,171,175,54,41,113,128,83,41,190,16,21,28,33,124,115,10,187,146,148,12,172,187,197,172,157,103,35,80,26,6,188,60,59,66,93,130,5,169,112,171,69,89,10,35,133,66,180,23,198,108,142,200,57,83,93,153,164,20,35,72,11,104,67,35,41,181,135,94,183,20,149,147,112,37,120,60,26,42,179,14,48,10,88,2,180,39,18,61,91,20,200,66,59,12,59,9,101,153,126,18,16,156,181,107,21,165,67,59,150,2,9,134,121,105,146,142,157,57,139,111,79,12,156,67,122,148,21,25,110,97,178,160,147,10,14,17,160,189};

int POSXS[200] = {137,26,145,22,23,128,66,131,150,117,148,47,147,195,174,17,73,74,137,120,158,73,41,17,155,41,78,110,46,129,97,30,157,20,59,47,106,18,81,21,22,157,58,121,193,86,139,152,86,131,22,187,37,53,160,98,154,79,54,7,135,86,90,122,11,63,155,139,25,26,18,1,85,131,145,106,21,126,25,26,19,28,33,39,63,63,43,50,179,141,111,37,42,15,183,142,112,62,33,125,198,34,51,79,14,137,80,197,80,124,31,76,32,152,175,70,137,59,106,167,120,67,60,90,84,72,112,149,85,86,25,4,58,63,131,192,188,92,48,153,152,148,149,21,136,93,42,19,165,35,32,133,179,103,141,30,191,108,136,7,162,150,24,105,65,109,80,83,36,51,4,185,131,187,32,185,159,116,88,51,151,45,12,154,134,143,129,84,78,164,63,163,158,171,101,127,191,89,12,174};
int POSYS[200] = {126,71,200,45,131,121,77,28,5,84,37,145,74,169,147,114,35,192,53,185,44,75,17,128,36,9,145,69,132,77,126,4,183,160,149,163,77,124,115,106,55,49,90,45,161,198,6,107,17,161,198,13,188,3,137,157,107,177,180,125,27,43,36,8,21,123,188,71,82,197,190,136,198,154,67,133,49,59,136,106,82,121,150,117,110,117,102,16,144,200,71,195,69,178,91,83,43,25,62,145,157,139,1,169,185,154,8,76,141,146,45,54,135,95,125,47,35,166,154,187,21,36,19,98,38,180,19,8,112,155,62,35,68,42,102,182,126,20,78,10,100,86,200,163,97,179,27,78,186,184,143,124,69,188,25,146,129,167,80,150,167,64,111,196,110,66,124,72,152,83,98,139,195,65,168,148,191,6,71,133,56,46,142,125,118,132,9,70,90,48,143,172,56,146,27,168,27,118,73,162};

//int POSXS[100] = {101,98,176,70,90,193,8,195,38,134,117,135,72,124,163,3,16,195,130,46,81,24,53,51,66,30,69,24,177,18,186,80,9,68,147,159,109,137,179,11,61,9,39,144,145,176,117,14,185,160,57,109,197,143,168,87,94,112,54,150,101,130,61,27,95,72,158,156,134,26,4,112,60,188,197,57,160,180,120,177,189,110,146,115,5,89,129,104,74,188,166,170,74,119,175,187,134,41,131,14};
//int POSYS[100] = {81,134,187,163,97,152,83,195,198,173,78,91,49,157,177,183,112,120,29,180,90,41,180,153,177,57,135,133,24,81,55,144,56,180,166,78,100,139,167,122,115,65,91,143,177,144,3,135,88,88,23,163,65,49,68,75,109,112,79,80,103,132,191,145,80,167,27,12,16,32,65,60,2,108,19,29,126,172,195,114,200,111,103,66,86,98,14,178,12,87,166,79,123,164,178,187,38,51,180,119};

// UZAKLAR HOT REGION
//int POSXS[200] = {3,98,52,91,38,89,25,91,90,40,63,57,90,21,0,88,23,24,64,30,83,89,95,39,80,15,63,70,8,53,89,26,23,84,50,15,23,66,56,29,62,72,28,41,36,78,13,91,29,50,79,68,15,70,13,95,89,52,68,98,12,75,83,78,19,43,1,32,13,45,57,79,42,53,93,90,55,91,5,81,33,23,83,35,16,2,96,68,86,94,68,92,25,89,92,30,7,77,8,73,26,10,126,5,27,139,103,109,162,159,100,55,24,178,195,189,128,18,15,36,6,145,28,127,158,113,75,165,61,64,157,101,52,147,32,185,44,16,14,154,164,148,152,193,93,158,84,189,0,197,114,69,112,60,31,133,137,159,70,50,69,66,186,151,57,121,153,170,181,119,13,43,174,83,132,157,49,111,46,1,154,4,79,50,41,133,183,1,150,160,182,195,24,104,165,128,191,190,194,13};
//int POSYS[200] = {95,115,67,103,114,51,97,139,61,94,116,79,145,120,70,106,138,106,125,140,135,63,69,65,52,50,110,111,142,124,80,100,76,124,61,125,131,125,84,109,97,58,133,119,76,147,68,80,91,73,69,121,68,102,79,96,143,71,50,141,118,102,102,60,150,86,113,89,50,105,101,74,54,135,54,81,129,148,109,128,123,115,117,144,104,90,117,94,63,94,105,89,90,125,102,99,58,75,95,114,87,64,26,27,161,105,189,198,82,74,45,89,53,92,87,52,26,84,101,65,137,89,87,159,163,151,158,100,111,126,19,49,123,61,154,53,7,59,111,194,138,144,112,107,176,79,92,41,152,109,71,140,21,1,120,132,116,182,127,105,52,10,147,33,56,52,109,108,158,174,158,194,36,187,9,48,1,134,181,115,31,100,114,37,65,143,111,28,76,79,115,3,116,187,21,147,195,122,144,60};
// YAKINLAR HOT REGION
//int POSXS[200] = {171,200,194,109,196,116,198,160,124,107,130,182,107,135,113,115,106,170,108,162,117,165,150,128,183,182,194,100,164,100,110,110,137,124,134,125,139,142,164,179,127,185,174,183,118,106,161,170,111,109,160,182,182,109,173,191,145,107,124,173,104,142,154,196,121,111,165,110,199,125,161,182,183,149,176,192,190,121,155,179,119,175,148,158,126,108,130,192,147,127,177,177,102,188,180,132,167,129,193,128,26,10,126,5,27,139,103,109,162,159,100,55,24,178,195,189,128,18,15,36,6,145,28,127,158,113,75,165,61,64,157,101,52,147,32,185,44,16,14,154,164,148,152,193,93,158,84,189,0,197,114,69,112,60,31,133,137,159,70,50,69,66,186,151,57,121,153,170,181,119,13,43,174,83,132,157,49,111,46,1,154,4,79,50,41,133,183,1,150,160,182,195,24,104,165,128,191,190,194,13};
//int POSYS[200] = {67,125,98,115,147,81,57,129,86,109,68,57,65,133,80,88,115,132,127,87,69,115,50,78,114,109,82,149,62,124,65,93,134,86,57,106,77,63,120,99,68,60,70,63,82,146,103,75,94,117,105,111,137,88,125,65,55,84,132,88,148,111,84,143,140,135,75,78,128,120,99,147,98,150,99,100,127,89,95,63,126,107,115,130,72,136,141,79,123,84,77,67,117,104,133,77,67,93,98,129,87,64,26,27,161,105,189,198,82,74,45,89,53,92,87,52,26,84,101,65,137,89,87,159,163,151,158,100,111,126,19,49,123,61,154,53,7,59,111,194,138,144,112,107,176,79,92,41,152,109,71,140,21,1,120,132,116,182,127,105,52,10,147,33,56,52,109,108,158,174,158,194,36,187,9,48,1,134,181,115,31,100,114,37,65,143,111,28,76,79,115,3,116,187,21,147,195,122,144,60};


int Node::getSiraId(int getid = -1)
{
    if (getid == -1) getid = getId();
    for(int i = 0; i < chSayisi; i++)
    {
        if (zincirDizi[i] == getid - 2)
        {
            benimSiraNo = i;
            return i;
        }
    }
    return -1;
}

void Node::zincirOlustur()
{
    EV << "ZİNCİR OLUŞTURMA BAŞIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
    liderNo = bazaEnYakiniBul();
    if (getNodeId() == (liderNo)) liderim = true;
    else liderim = false;

    onceMiSonraMi[liderNo] = -1;

    if (liderim)
    {
        char * cc = new char[8];
        sprintf(cc, "#000000");
        getDisplayString().setTagArg("i", 1, cc); //renk ata
        clusterHead = server;

        gate("cikisKapi")->connectTo(server->gate("girisKapi"));
        EV << getNodeId() << "--> BAZA BAĞLANDIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" ;
    }
    else
    {
        int en_uzak_sira_id = bazaEnUzagiBul();
        if(en_uzak_sira_id == benimSiraNo) baslangicim = true;

        //zincirDizi = new int [chSayisi];
        zincirDizi[0] = en_uzak_sira_id;
        secilenler[en_uzak_sira_id] = true;
        EV << zincirDizi[0] << ",";
        int a;
        for(int i = 1; i < chSayisi; i++)
        {
            a = secilmemislerinEnYakini(zincirDizi[i-1]);
            if(a == -1)
            {
                baslangicim = true;
                zincirDizi[i] = chListesi[i];
                EV << zincirDizi[i] << ",";
                continue;
            }
            zincirDizi[i] = a;
            if (a == liderNo) EV << " ---> " << zincirDizi[i] << " <--- ";
            else EV << zincirDizi[i] << " ";
        }
        if (a == getNodeId()) sonum = true; // Son a değeri son düğüm olacak.
        EV << "\n";

        bool oncesi = true;
        for(int i = 0; i < chSayisi; i++)
        {
            if (zincirDizi[i] == liderNo) oncesi = false;
            if (oncesi) onceMiSonraMi[i] = ONCE;
            else onceMiSonraMi[i] = SONRA;
            if (zincirDizi[i] == liderNo) onceMiSonraMi[i] = NE_ONCE_NE_SONRA; // fazla satır olmaması için
        }

        // ÖLEN KONTROLLERİ SONRA EKLE
        EV << getNodeId() << "  AAAAAAAAAAAAAAAAAA     "; for (int i = 0; i < NUM_NODES; i++) EV << zincirDizi[i] << ", "; EV << "\n";
        EV << getNodeId() << "  AAAAAAAAAAAAAAAAAA     "; for (int i = 0; i < NUM_NODES; i++) EV << onceMiSonraMi[i] << ", "; EV << "\n";
        if(!olenler[getSiraId()])
        {
            char * chr = new char[128];
            if (onceMiSonraMi[getSiraId()] == ONCE)
            {
                sprintf(chr, "LeachBasic.nd[%d]", zincirDizi[getSiraId()+1]);
                clusterHead = getModuleByPath(chr);
                gate("cikisKapi")->connectTo(clusterHead->gate("girisKapi"));
                int chNo = zincirDizi[getSiraId()+1];
                chDistance = calculateDistance(xPosition, yPosition, POSXS[chNo], POSYS[chNo]);
            }
            else if(onceMiSonraMi[getSiraId()] == SONRA)
            {
                sprintf(chr, "LeachBasic.nd[%d]", zincirDizi[getSiraId() - 1]);
                clusterHead = getModuleByPath(chr);
                int chNo = zincirDizi[getSiraId()-1];
                chDistance = calculateDistance(xPosition, yPosition, POSXS[chNo], POSYS[chNo]);
                if (onceMiSonraMi[getSiraId()-1] == NE_ONCE_NE_SONRA)
                {// eğer ch den bir sonraki isem diğer kapı dolu olduğu için ikinci kapıya bağlan
                    gate("cikisKapi")->connectTo(clusterHead->gate("girisKapi2"));
                }
                else
                {
                    gate("cikisKapi")->connectTo(clusterHead->gate("girisKapi"));
                }
            }

            EV << "ZİNCİR OLUŞTURMA SONUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n";
//            char * cc = new char[8];
//            sprintf(cc, "#BBBBBB");
//            getDisplayString().setTagArg("i", 1, cc); //renk ata
        }
    }
}


void Node::bazaUzakliklariHesapla() // Bir kere başlangıçta çalışacak
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        bazaUzakliklar[i] = calculateDistance(bazX, bazY, POSXS[i], POSYS[i]);//calculateDistance();
    }
}

void Node::dugumeUzakliklariHesapla(int dugumSiraNo) // En başta her düğüm için çalışacak
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        dugumUzakliklari[dugumSiraNo][i] = calculateDistance(POSXS[dugumSiraNo], POSYS[dugumSiraNo] , POSXS[i], POSYS[i]);//calculateDistance();
    }
}

int Node::secilmemislerinEnYakini(int dugumNo)
{
    double en_yakin = 9999999999999.0; /* TO DO */
    int en_yakin_sira  = -1;
    bool tamamiSecildi = true;
    for(int i = 0; i < chSayisi; i++)
    {
        int nomuz = chListesi[i];
        if (!secilenler[nomuz]) tamamiSecildi = false;
        if (dugumUzakliklari [dugumNo][nomuz] < en_yakin && nomuz != dugumNo && !secilenler[nomuz])
        {
            en_yakin = dugumUzakliklari [dugumNo][nomuz];
            en_yakin_sira = nomuz;
        }
    }
    if(tamamiSecildi) return en_yakin_sira; //-1
    secilenler[en_yakin_sira] = true;
    return en_yakin_sira;
}


int Node::getZincirSira(int getid)
{
    for(int i = 0; i < chSayisi; i++)
    {
        if (zincirDizi[i] == getid) return i;
    }
    return -1;
}

int Node::bazaEnUzagiBul()
{
    int en_uzak_id = -1;
    double en_uzak = .0;

    for(int i = 0; i < chSayisi; i++ )
    {
        if (bazaUzakliklar[chListesi[i]] > en_uzak)
        {
            en_uzak = bazaUzakliklar[chListesi[i]];
            en_uzak_id = chListesi[i];
        }
    }
    return en_uzak_id;
}

int Node::bazaEnYakiniBul()
{
    int en_yakin_id = -1;
    double en_yakin = 99999999999999999.9;

    for(int i = 0; i < chSayisi; i++ )
    {
        if (bazaUzakliklar[chListesi[i]] < en_yakin)
        {
            en_yakin = bazaUzakliklar[chListesi[i]];
            en_yakin_id = chListesi[i];
        }
    }
    return en_yakin_id;
}


/* Buraya kadarki fonksiyonlar sadece CH ler için */


void Node::die()
{
    cancelEvent(nextRoundEvent);
    head2baseMsg *hmsg = new head2baseMsg("die");
    hmsg->setSource(getNodeId());
    sendDirect(hmsg, server, "in");
    cMessage * clearMsg = new cMessage("clr");
    scheduleAt(simTime() + 2.1, clearMsg); //3 olursa sonraki zinciri etkiler, 2 den az olursa o ankini
}

double Node::reduceBattery(double distance, int sendOrReduce, int type = INFO, int packetCount = 1)
{
    int localK;
    if(type == DATA) localK= (K*packetCount);
    if(type == INFO) localK= ((K/4)*packetCount);
    double redu;
    if (sendOrReduce == SEND_REDUCE)
    {
        if (distance < THRS_DIST) redu = (E_ELEC * localK) + ( E_FS * localK * pow(distance, 2) );
        else                      redu = (E_ELEC * localK) + ( E_MP * localK * pow(distance, 4) );
    }
    else if (sendOrReduce == RECEIVE_REDUCE)
    {
        redu = E_ELEC * localK;
    }
    else if (sendOrReduce == DATA_AGGREGATION_REDUCE)
    {
        redu = aggBattery * packetCount;
    }

    battery -= redu;
    if (battery > 0.0)
    {
        head2baseMsg * msg3 = new head2baseMsg("myBattery");
        msg3->setSource(getNodeId());
        msg3->setTotalExpendedEnergy(battery);
        sendDirect(msg3, server, "in");
    }
    else
    {
        head2baseMsg * msg3 = new head2baseMsg("myBattery");
        msg3->setSource(getNodeId());
        msg3->setTotalExpendedEnergy(0.0);
        sendDirect(msg3, server, "in");
    }

    char *cs = new char[32];
    if ( battery > (fullBattery*0.80) )
    {
        sprintf(cs, "status/battery_80");
        getDisplayString().setTagArg("i2", 0, cs); // status ikon ata
    }
    else if ( battery > (fullBattery*0.60) )
    {
        sprintf(cs, "status/battery_60");
        getDisplayString().setTagArg("i2", 0, cs); // status ikon ata
    }
    else if ( battery > (fullBattery*0.40) )
    {
        sprintf(cs, "status/battery_40");
        getDisplayString().setTagArg("i2", 0, cs); // status ikon ata
    }
    else if ( battery > (fullBattery*0.20) )
    {
        sprintf(cs, "status/battery_20");
        getDisplayString().setTagArg("i2", 0, cs); // status ikon ata
    }
    else if ( battery <= (fullBattery*0.20) && battery > (fullBattery*0.05))
    {
        sprintf(cs, "status/battery_0");
        getDisplayString().setTagArg("i2", 0, cs); // status ikon ata
    }
    else
    {
        die();
        iAmDead = true;
        char *ci = new char[32];
        sprintf(ci, "old/x_cross");
        getDisplayString().removeTag("i2");
        getDisplayString().setTagArg("i", 0, ci); // ikon ata
    }
    return redu;
}

void Node::beginNextRound()
{
    globalRound++;
    if (curRound == CLUSTER_DEFAULT_MEMBER-1) curRound = 0;
    else curRound++;
    receivedRoundCountVector.record(globalRound);
}

int Node::getNodeId()
{
   return getId()-2;  /*DİKKATTTTTTTTTT -2 tehlikeli, deneme için sadece*/
}

void Node::updateDisplayStringPositionAndTag(int x, int y)
{
    getDisplayString().setTagArg("p", 0, x);
    getDisplayString().setTagArg("p", 1, y);

    char* chr = new char[16];
    sprintf(chr, "(%d,%d)", x, y); //
    /*getDisplayString().setTagArg("t", 0, chr);*/ /* Bu kısım ister kaldırılır, ister kullanılır, Modül üerinde koordinatı yazar.*/
}

double Node::treshold(int t_algorithm = LEACH)
{
    if (t_algorithm == LEACH)    return (P / (  1.0  -  P * (globalRound % (int)(1.0/P))  ));
    if (t_algorithm == IMPLEACH) return  (P / (  1.0  -  P * (globalRound % (int)(1.0/P))  )) * sqrt(battery / fullBattery);
    if (t_algorithm == CCRP)
    {
        double Ec = battery;
        double Ei = fullBattery;
        int Rc = globalRound;
        return  (double)(P / (  1.0  -  P * (Rc % (int)(1.0/P))  )) * ( (Ec/Ei) + (1-(Ec/Ei)) * (Nb / (1/P - 1)));
    }
    if (t_algorithm == WSTLEACH)
    {
        double Eres = battery;
        double E0 = fullBattery;
        int Rc = globalRound;
        double W1 = 0.2;
        double W2 = 0.3;
        double W3 = 0.5;
        double result = (double)(P / (  1.0  -  P * (Rc % (int)(1.0/P))  )) * (  (W1 * (Eres/E0))  +  (W2 * (Nb/ (P * NUM_NODES)))  +  (W3 * (1/dBS))  );
        EV <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  " << (W2 * (Nb/ (P * NUM_NODES))) << "   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1\n";
        return result;
    }
    else return .0;
}

void Node::beginHeadSelection()
{
    double nDeg = uniform(0.0, 1.0);
    double tDeg = treshold(algorithm);

    EV << "tDeg = " << tDeg << "\n";
    EV << "nDeg = " << nDeg << "\n";

    if (gDeg == 0)
    {
        if (nDeg < tDeg)
        {
            iAmHead = true;
            gDeg = (int)(1.0/P);
        }
        else iAmHead = false;
    }
    else if (gDeg > 0)
    {
        gDeg --;
        iAmHead = false;
    }

//    if (getNodeId() % int(1/P) == curRound) iAmHead = true;
//    else iAmHead = false;

    if (iAmHead)
    {
        EV << getNodeId() << " --> CUR_ROUND : " << globalRound << "===========" << "(" << xPosition << ", " << yPosition << ") " <<"\n";
        broadcastSent = false; // eğer yeniden ch olursa diye
        chDistance = MIN_DISTANCE;
        headWaitEvent = new cMessage("hwM");

        char *ci = new char[32];
        char *cc = new char[7];

        sprintf(ci, "misc/node");
        sprintf(cc, color);

        getDisplayString().setTagArg("i", 0, ci); //ikon ata
        getDisplayString().setTagArg("i", 1, cc); //renk ata
    }
    else
    {
        EV << getNodeId() << " --> CUR_ROUND : " << globalRound << " <---------------------------------------------------\n";
        sprintf(chFullPath, "LeachBasic.base");
        clusterHead = server;
        char *ci = new char[32];
        sprintf(ci, "misc/node_s");

        getDisplayString().setTagArg("i", 0, ci); //ikon ata
        getDisplayString().setTagArg("i", 1, "#BBBBBB"); //renk ata
    }
}

void Node::initialize()
{
    if(first_init)
    {
        battery = par("battery");
        fullBattery = par("battery");
        globalRound = 1;
        color = generateRandomColor();
        first_init = false;
        mainModule = getModuleByPath("LeachBasic");
        server = getModuleByPath("LeachBasic.base");
        WATCH(battery);
        WATCH(globalRound);
        WATCH(chFullPath);
        WATCH(Nb);

        receivedRoundCountVector.setName("Received Round Count Vector IN NODE ");
        receivedRoundCountVector.record(globalRound);

        // Her modülün bunu yapması mantıksız, ama ana modülün initialize kısmını bulduğumda oraya taşıyacağım, şimdilik dursun.
        P = mainModule->par("p").doubleValue();
        E_AMP = mainModule->par("eAmp").doubleValue();
        E_ELEC = mainModule->par("eElec").doubleValue();
        E_MP = mainModule->par("eMp").doubleValue();
        E_FS = mainModule->par("eFs").doubleValue();
        THRS_DIST = mainModule->par("thresholdDist").doubleValue();
        aggBattery = mainModule->par("aggregation");

        NUM_NODES = mainModule->par("numNodes");
        CLUSTER_DEFAULT_MEMBER = (int)(1 / P);
        NUM_CLUSTERS = (NUM_NODES / CLUSTER_DEFAULT_MEMBER);
        K = mainModule->par("k");
        range = mainModule->par("Range");
        algorithm = mainModule->par("algorithm");
        gDeg = 0;

        int xMax = mainModule->par("maxX");
        int yMax = mainModule->par("maxY");

        xPosition = POSXS[getNodeId()];//intuniform(0, xMax, 1);
        yPosition = POSYS[getNodeId()];//intuniform(0, yMax, 1);
        updateDisplayStringPositionAndTag(xPosition, yPosition);
        EV << xPosition << "," << yPosition << "\n"; // Yapay Zeka proje için

        int serX = mainModule->par("bazX");
        int serY = mainModule->par("bazY");
        if (algorithm != LEACH && algorithm != IMPLEACH) // leach ve impleach de Nb hesaplama işlemleri başlatılmayavak
        {
            EV << "BLAAAAAA\n";
            head2baseMsg * nmsg1 = new head2baseMsg("myXY");
            nmsg1->setSource(getNodeId());
            nmsg1->setPosX( xPosition );
            nmsg1->setPosY( yPosition );
            nmsg1->setKind(1); // Renk
            sendDirect(nmsg1, server, "in");
            reduceBattery(calculateDistance(xPosition, yPosition, serX, serY), SEND_REDUCE, INFO, 1);
        }

        if (xMax > yMax) networkRadius = xMax/2.0;
        else  networkRadius = yMax/2.0;
        dBS = calculateDistance(xPosition, yPosition, serX, serY);
        posXs = new int[NUM_NODES];
        posYs = new int[NUM_NODES];
        for(int i = 0; i < NUM_NODES; i++)
        {
            posXs[i] = 0;
            posYs[i] = 0;
        }

        bazX = mainModule->par("bazX");
        bazY = mainModule->par("bazY");
        chListesi = new int [NUM_NODES];
        bataryalar = new double [NUM_NODES];
        bazaUzakliklar = new double [NUM_NODES];
        dugumUzakliklari = new double * [NUM_NODES];
        secilenler = new bool [NUM_NODES];
        onceMiSonraMi = new int [NUM_NODES];
        olenler = new bool [NUM_NODES];
        zincirDizi = new int [NUM_NODES];
        for(int i = 0; i < NUM_NODES; i++)
        {
            olenler[i] = false;
            bataryalar[i] = fullBattery;
            bazaUzakliklar[i] = .0; // Öylesine
            dugumUzakliklari[i] = new double [NUM_NODES];
            dugumeUzakliklariHesapla(i);
        }

        benimSiraNo = getNodeId();
        bazaUzakliklariHesapla();
    }

    for(int i = 0; i < NUM_NODES; i++)
    {
        secilenler[i] = false; // Her cevrim düğümler baştan seçilmemiş olur
        onceMiSonraMi[i] = -1;
        chListesi[i] = -3;
        zincirDizi[i] = -2;
    }

    clusterMembers = new int [NUM_NODES]; // Maximum 100 ya da girilen sayı kadar düğümlük cluster için bellek ayırımı, düz hesap boş olanlar -1 olacak
    clusterMemberXs = new int [NUM_NODES];
    clusterMemberYs = new int [NUM_NODES];
    for(int i = 0; i < NUM_NODES; i++)
    {
        clusterMembers[i] = -1;
        clusterMemberXs[i] = -0.1;
        clusterMemberYs[i] = -0.1;
    }

    zincirEvent = new cMessage("zM");
    nextRoundEvent = new cMessage("nrM");
    waitEvent = new cMessage("wM");
    headWaitEvent = new cMessage("hwM");
    broadcastEvent = new cMessage("bcM");
    littleBroadcastEvent = new cMessage("lbcM");
    node2headDataMessage = new cMessage("n2hdM");
    node2headChooseMessage = new cMessage("n2hcM");
    ch2baseMessage = new cMessage("h2bM");

    dieCount = 0;
    totalExpendedEnergy = 0;
    clusterMemberCount = 0;
    chDistance = MIN_DISTANCE;
    clusterHead = server;

    chSayisi = 0;
    gelenMesajSayisiIlk = 0; // Bunlara gerek kalmayacak galiba bu ikisine
    gelenMesajSayisiSon = 0; //
    liderGelenMesajSayisi = 0;
    liderNo = -1;
    liderim = false;
    baslangicim = false;
    sonum = false;

    beginHeadSelection();
    if(iAmHead)
    {
        cancelEvent(waitEvent);
        cancelEvent(headWaitEvent);
        scheduleAt(simTime()+1.0, headWaitEvent);
    }
    else
    {
        cancelEvent(waitEvent);
        cancelEvent(headWaitEvent);
        scheduleAt(simTime()+1.5, waitEvent);
    }
}

void Node::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(), "clr") == 0)
    {
        if (gate("girisKapi")->isConnected()) gate("girisKapi")->disconnect();
        if (gate("girisKapi2")->isConnected()) gate("girisKapi2")->disconnect();
        if (gate("cikisKapi")->isConnected()) gate("cikisKapi")->disconnect();
    }
    if(strcmp(msg->getName(), "info") == 0)
    {
        reduceBattery(dBS*123456, RECEIVE_REDUCE, INFO); // uzaklık önemli değil zaten 123456....
        head2baseMsg * msg1 = check_and_cast<head2baseMsg *>(msg);
        std::string datastr = msg1->getMes();
        std::istringstream iss0(datastr);
        std::string token__;
        std::string token;

        EV << datastr << "\n";

        int i = 0;
        while(std::getline(iss0, token__, '_'))
        {
            std::istringstream iss1(token__);
            std::getline(iss1, token, ':');
            posXs[i] = atoi( token.c_str() );
            std::getline(iss1, token, ':');
            posYs[i] = atoi( token.c_str() );
            i++;
        }
        cMessage * msg2 = new cMessage("NbBroadcastEvent");
        simtime_t stt2 = 0.3;
        scheduleAt(stt2, msg2);
    }
    if(strcmp(msg->getName(), "NbBroadcastEvent") == 0)
    {
        double distanceToMe = .0;
        broadcastMsg * bcmsg;
        for(int i = 0; i < NUM_NODES; i++)
        {
            distanceToMe = calculateDistance(xPosition, yPosition, posXs[i], posYs[i]);
            if (distanceToMe < range)
            {
                bcmsg = new broadcastMsg("NbBc");
                bcmsg->setPosX(xPosition);
                bcmsg->setPosY(yPosition);
                bcmsg->setChFullPath(getFullPath().c_str());
                bcmsg->setKind(2); // BLUE DOT
                bcmsg->setSource(getNodeId());
                char *chr = new char[32];
                sprintf(chr, "LeachBasic.nd[%d]",i);
                sendDirect(bcmsg, getModuleByPath(chr), "in");
            }
        }
        reduceBattery(range, SEND_REDUCE, INFO);
    }
    if(strcmp(msg->getName(), "NbBc") == 0)
    {
        reduceBattery(range*123456, RECEIVE_REDUCE, INFO); // uzaklık önemli değil zaten 123456....
        broadcastMsg * msg1 = check_and_cast<broadcastMsg *>(msg);
        cModule * senderModule = msg1->getSenderModule();
        msg1->setName("Nb");
        msg1->setKind(3);
        sendDirect(msg, senderModule, "in");
        reduceBattery(calculateDistance(xPosition, yPosition, msg1->getPosX(), msg1->getPosY()), SEND_REDUCE, INFO);
    }
    if(strcmp(msg->getName(), "Nb") == 0)
    {
        broadcastMsg * msg1 = check_and_cast<broadcastMsg *>(msg);
        reduceBattery(calculateDistance(xPosition, yPosition, msg1->getPosX(), msg1->getPosY()), SEND_REDUCE, INFO);
        Nb++;
    }
    if (!iAmDead)
    {
    /**/if(strcmp(msg->getName(), "nrM") == 0)
        {
            cancelEvent(waitEvent);
            cancelEvent(headWaitEvent);
            EV << msg->getOwner()->getFullName() << " : beginNextRound(); \n";
            iAmHead = false;
            chDistance = MIN_DISTANCE;
            chooseSent = false;
            broadcastSent = false;
            littleBroadcastSent = false;
            broadcastArrived = false;
            noCh = false;
            ch2headMsgStr = "";
            chFullPath = new char[128];
            sprintf(chFullPath, "LeachBasic.base");
            clusterHead = getModuleByPath(chFullPath);

            if (iAmDead)
            {
                return;
            }

            if (gate("girisKapi")->isConnected()) gate("girisKapi")->disconnect();
            if (gate("girisKapi2")->isConnected()) gate("girisKapi2")->disconnect();
            if (gate("cikisKapi")->isConnected()) gate("cikisKapi")->disconnect();
            beginNextRound(); // Round ilerlet, sonuncudaysa 1 e
            initialize();
        }


    /**/if(strcmp(msg->getName(), "zM") == 0)
        {
            EV << "CH LİSTESİ  ";
            for(int p = 0; p < chSayisi; p++) EV << chListesi[p] << ",";
            EV << "\n";
            zincirOlustur();
        }

    /**/if(strcmp(msg->getName(), "bcM") == 0) // Modül: standart düğüm, büyük reklam mesajı buraya düşer.
        {
            broadcastMsg * msg1 = check_and_cast<broadcastMsg *>(msg);
            broadcastArrived = true;
            int broX = msg1->getPosX(); // X kardeş, Y kardeş :)
            int broY = msg1->getPosY();
            int source_no = msg1->getSource();
            double dist = calculateDistance(broX, broY, xPosition, yPosition);
            std::string str_f_path = msg1->getChFullPath();
            std::string str_color = msg1->getColor();
            if(iAmHead)
            {
                cancelEvent(zincirEvent); // her bilgi gelişinde sıfırlanacak, zaten hiç değişmemiş olacak çünkü hep aynı saniyede işlemler
                chListesi[chSayisi] = source_no;
                chSayisi ++;

                EV << "ZİNCİRE HAZIRLIK " << source_no << " KAYDEDİLİDİ\n";
                scheduleAt(simTime()+0.1, zincirEvent);

//                EV << "(" << xPosition << ", " << yPosition << ") " << "nd["<< getNodeId()<<"].head = " << str_f_path << "=====already===ch=======\n";
//                chDistance = MIN_DISTANCE; // ch kendisi
//                sprintf(chFullPath, getFullPath().c_str());
//                clusterHead = getModuleByPath(chFullPath);
//                return;
            }
            else if (chDistance == MIN_DISTANCE) // ch değilim, ama uzaklık -1, demek ki hiç set edilmemiş.
            {
                EV << "(" << xPosition << ", " << yPosition << ") nd["<< getNodeId()<<"] --> dist: " << dist << ", chDistance: " << chDistance << "=====first=bc=======\n";
                chDistance = dist;
                sprintf(chFullPath, str_f_path.c_str());

                EV << "(" << xPosition << ", " << yPosition << ") " << "nd["<< getNodeId()<<"].head = " << str_f_path << "\n";
                getDisplayString().setTagArg("i", 1, str_color.c_str());
                clusterHead = getModuleByPath(chFullPath);
                return;
            }
            if (dist < chDistance) // yeni broadcast'çi eskisinden daha yakınsa
            {
                sprintf(chFullPath, str_f_path.c_str());
                EV << "nd["<< getNodeId()<<"] --> dist: " << dist << ", chDistance: " << chDistance << "====new=ch=better========\n";
                EV << "nd["<< getNodeId()<<"].head = " << str_f_path << "\n";
                chDistance = dist;
                clusterHead = getModuleByPath(chFullPath);
                getDisplayString().setTagArg("i", 1, str_color.c_str());
                return;
            }
            reduceBattery(chDistance, RECEIVE_REDUCE, INFO);
            if (iAmDead)return;
        }
    /**/if(strcmp(msg->getName(), "lbcM") == 0) // Modül: standart düğüm, küme içi yayın mesajı
        {
            // Şimdilik boş, önemsiz
            reduceBattery(chDistance, RECEIVE_REDUCE);
            if (iAmDead)return;
        }
    /**/if (strcmp(msg->getName(), "n2hdM") == 0) // Modül: ch, broadcast'tan sonra gelen mesajlar buraya düşer.
        {
            node2headMsg *nmsg = check_and_cast<node2headMsg *>(msg);
            reduceBattery( calculateDistance(xPosition, yPosition, nmsg->getPosX(), nmsg->getPosY()), RECEIVE_REDUCE);
            if (iAmDead) return;
            if (nmsg->getDie() == true) dieCount++;
            totalExpendedEnergy += nmsg->getExpendedEnergy();
            char *c = new char[64];
            sprintf(c, "%d:", nmsg->getPosX());
            ch2headMsgStr.append(c);
            sprintf(c, "%d:", nmsg->getPosY());
            ch2headMsgStr.append(c);
            sprintf(c, "%f:", nmsg->getExpendedEnergy());
            ch2headMsgStr.append(c);
            sprintf(c, "%d", nmsg->getDie());
            ch2headMsgStr.append(c);
            ch2headMsgStr.append("_"); // ilgili düğümün bilgisi stringe eklenince bitirmek için '_' koydum, sonra base'de split edeceğim.
        }

    /**/if (strcmp(msg->getName(), "n2hcM") == 0) // Modül: ch, kümeiçi broadcast'tan sonra gelen mesajlar buraya düşer.
        {
            node2headMsg *nmsg = check_and_cast<node2headMsg *>(msg);
            reduceBattery( calculateDistance(xPosition, yPosition, nmsg->getPosX(), nmsg->getPosY()), RECEIVE_REDUCE);
            if (iAmDead) return;
            clusterMemberCount++;
            clusterMembers[clusterMemberCount-1] = nmsg->getSource();
            char *c = new char[64];
            sprintf(c, "%d:", nmsg->getPosX());
        }
    /**/if (strcmp(msg->getName(), "wM") == 0) // Modül: standart düğüm
        {
            cancelEvent(waitEvent);
            cancelEvent(nextRoundEvent);
            if (chooseSent && broadcastArrived) // ch seçildi, data gönderilecek
            {
                node2headMsg *msg2 = new node2headMsg("n2hdM");
                msg2->setSource(getNodeId());
                msg2->setPosX( xPosition );
                msg2->setPosY( yPosition );
                msg2->setKind(0); // Kırmızı nokta
                msg2->setExpendedEnergy(reduceBattery(chDistance, SEND_REDUCE, DATA));
                msg2->setDie(iAmDead);
                EV << this->getNodeId() << " --> Waiting Complete, Trying to send message to: " << chFullPath << "\n";
                sendDirect(msg2, clusterHead, "in");
                scheduleAt(simTime()+1.5, nextRoundEvent); // 4 saniye sonra yeni roundun mesajı gönderilecek
                if (!iAmDead) // Mesaj gönderdikten sonra ölmeyeceksem
                {
                    getDisplayString().setTagArg("i", 0, "misc/node_s"); //ikon ata
                }
                else
                {
                    getDisplayString().setTagArg("i", 0, "old/x_cross");
                }
            }
            else if (!chooseSent && chDistance != MIN_DISTANCE) //ch seçildi ama choose mesajı gönderilmedi
            {
                node2headMsg *msg2 = new node2headMsg("n2hcM");
                msg2->setSource(getNodeId());
                msg2->setPosX( xPosition );
                msg2->setPosY( yPosition );
                msg2->setKind(0); // Kırmızı nokta
                msg2->setExpendedEnergy(reduceBattery(chDistance, SEND_REDUCE, INFO));
                msg2->setDie(iAmDead);
                EV << this->getNodeId() << " --> I choose you message to: " << chFullPath << "\n";
                clusterHead = getModuleByPath(chFullPath);
                sendDirect(msg2, clusterHead, "in");
                chooseSent = true;
                if (iAmDead) // Mesaj gönderdikten sonra ölmeyeceksem
                {
                    getDisplayString().setTagArg("i", 0, "old/x_cross");
                }
                scheduleAt(simTime() + 1.0, waitEvent);
            }
            else if (noCh) // broadcast gelmedi,
            {
                reduceBattery(dBS, SEND_REDUCE, DATA);
                head2baseMsg *msg2 = new head2baseMsg("h2bM(n2b)");
                sendDirect(msg2, server, "in"); // Sadece enerji düşecek, baz mesaja tepki vermeyecek
                scheduleAt(simTime()+1.5, nextRoundEvent);
                if (!iAmDead) // Mesaj gönderdikten sonra ölmeyeceksem
                {
                    getDisplayString().setTagArg("i", 0, "misc/node_s"); //ikon ata // 4 saniye sonra yeni roundun mesajı gönderilecek
                }
                else
                {
                    getDisplayString().setTagArg("i", 0, "old/x_cross");
                }
            }
            else if (!broadcastArrived)
            {
                noCh = true;
                cancelEvent(waitEvent);
                scheduleAt(simTime() + 1.0, waitEvent);
            }

        }
    /**/if (strcmp(msg->getName(), "hwM") == 0) // Modül: ch: broadcast yapar, mesaj gelmesini bekler, hepsi gelince baza yollar.
        {
            if (!broadcastSent)
            {
                cancelEvent(headWaitEvent);
                sprintf(chFullPath, getFullPath().c_str());
                clusterHead = getModuleByPath(chFullPath);
                chDistance = MIN_DISTANCE;
                char *chr = new char[16];
                broadcastMsg *bcmsg = new broadcastMsg();
                if(getNodeId() == 0) EV << xPosition << ", " << yPosition << "\n";
                for(int i = 0; i < NUM_NODES; i++)
                {
                    sprintf(chr, "LeachBasic.nd[%d]",i);
                    bcmsg = new broadcastMsg("bcM");
                    bcmsg->setPosX(xPosition);
                    bcmsg->setPosY(yPosition);
                    bcmsg->setChFullPath(getFullPath().c_str());
                    bcmsg->setColor(color);
                    bcmsg->setKind(2); // BLUE DOT
                    bcmsg->setSource(getNodeId());
                    broadcastEvent = check_and_cast<cMessage *> (bcmsg);
                    //if(i != getNodeId()) sendDirect(broadcastEvent, getModuleByPath(chr), "in");
                    sendDirect(broadcastEvent, getModuleByPath(chr), "in");
                }
                broadcastSent = true;
                totalExpendedEnergy = reduceBattery(networkRadius*2.82, SEND_REDUCE, INFO);
                if (iAmDead) return;
                scheduleAt(simTime()+1.0, headWaitEvent); // 2 sn sonra düğümler geri mesaj dönmüş olacak
            }
            else if (littleBroadcastSent)// ch, broadcast'tan sonra düğümlerden mesajlar alındıktan sonra self mesaj ile buraya girer
            {
                cancelEvent(nextRoundEvent);
                if (clusterMemberCount > 1) reduceBattery(NO_DISTANCE, DATA_AGGREGATION_REDUCE, INFO, clusterMemberCount);
                totalExpendedEnergy += reduceBattery( chDistance, SEND_REDUCE , DATA, clusterMemberCount); // Zincir oluşurken chDistance a gönderilecek düğüme uzaklık atanmıştı

                if (baslangicim || sonum)
                {
                    ch2chMsg * chmsg1 = new ch2chMsg("ch2ch");
                    chmsg1->setMessageCount(clusterMemberCount);
                    chmsg1->setDistance(chDistance);
                    send(chmsg1, "cikisKapi");
                    if(iAmDead)
                    {
                        if (gate("girisKapi")->isConnected()) gate("girisKapi")->disconnect();
                        if (gate("girisKapi2")->isConnected()) gate("girisKapi2")->disconnect();
                        if (gate("cikisKapi")->isConnected()) gate("cikisKapi")->disconnect();
                    }
                }
//                if (iAmDead) return;
//                EV << this->getNodeId() <<" --> Waiting Complete, SENDING ALL PACKETS!";
//                head2baseMsg *msg2 = new head2baseMsg("h2bM");
//                msg2->setSource(getId());
//                msg2->setPosX( xPosition );
//                msg2->setPosY( yPosition );
//                msg2->setMes(ch2headMsgStr.c_str());
//                msg2->setTotalExpendedEnergy(totalExpendedEnergy);
//                msg2->setDieCount(dieCount);
//                sendDirect(msg2, server, "in");
//                //char *cc = new char[7];
                char *ci = new char[32];
                if (!iAmDead)
                {
                    sprintf(ci, "misc/node_s");
                    //sprintf(cc, "#FFFFFF");
                    getDisplayString().setTagArg("i", 0, ci); //ikon ata
                    //getDisplayString().setTagArg("i", 1, cc); //renk ata
                }
                scheduleAt(simTime()+1.0, nextRoundEvent); // 1 saniye sonra yeni round
            }
            else // broadcastSent && !littleBroadcastSent
            {
                char *chr = new char[16];
                broadcastMsg *lbcmsg = new broadcastMsg();
                if(getNodeId() == 0) EV << xPosition << ", " << yPosition << "\n";

                double maxdist = .0, dis;
                for(int i = 0; i < clusterMemberCount; i++)
                {
                    dis = calculateDistance(xPosition, yPosition, clusterMemberXs[i], clusterMemberYs[i]);
                    if (dis > maxdist)
                    {
                        maxdist = dis;
                    }
                }

                for(int i = 0; i < clusterMemberCount; i++)
                {
                    sprintf(chr, "LeachBasic.nd[%d]",clusterMembers[i]);
                    lbcmsg = new broadcastMsg("lbcM");
                    lbcmsg->setKind(3); // white DOT
                    littleBroadcastEvent = check_and_cast<cMessage *> (lbcmsg);
                    sendDirect(littleBroadcastEvent, getModuleByPath(chr), "in");
                }
                littleBroadcastSent = true;
                reduceBattery(maxdist, SEND_REDUCE, INFO); // Maxdist, cluster içi maximum uzaklık
                if (iAmDead) return;
                scheduleAt(simTime()+1.0, headWaitEvent); // 1 saniye sonra ch --> base
            }
        }
    /**/if(strcmp(msg->getName(), "ch2ch") == 0)
        {
            ch2chMsg * chmsg1 = check_and_cast<ch2chMsg *>(msg);
            double senderDistance = chmsg1->getDistance();
            double senderMesCount = chmsg1->getMessageCount();
            reduceBattery(senderDistance, RECEIVE_REDUCE, DATA, senderMesCount); // DATA ya da INFO olması önemli değil...

            if(liderim)
            {
                if (liderGelenMesajSayisi == 0)
                {
                    liderGelenMesajSayisi++;
                    clusterMemberCount += senderMesCount; // gelen mesaj sayısını da kendi küme toplamına ekledik
                }
                else if (liderGelenMesajSayisi == 1)
                {
                    liderGelenMesajSayisi++; // artık 2 belki işe yarar diye yine de artırdım
                    clusterMemberCount += senderMesCount;
                    int newMessageCount = clusterMemberCount + senderMesCount;
                    delete chmsg1;
                    head2baseMsg *msg2 = new head2baseMsg("h2bM");
                    send(msg2, "cikisKapi");
                    reduceBattery(dBS, SEND_REDUCE, DATA, clusterMemberCount); // artık tamamı bu düğüme bağlı bir küme imiş gibi
                    if(iAmDead)
                    {
                        if (gate("girisKapi")->isConnected()) gate("girisKapi")->disconnect();
                        if (gate("girisKapi2")->isConnected()) gate("girisKapi2")->disconnect();
                        if (gate("cikisKapi")->isConnected()) gate("cikisKapi")->disconnect();
                    }
                }
                return;
            }

            int newMessageCount = clusterMemberCount + senderMesCount;
            chmsg1->setMessageCount(newMessageCount);
            chmsg1->setDistance(chDistance);
            send(chmsg1, "cikisKapi");
            reduceBattery(chDistance, SEND_REDUCE, DATA, newMessageCount);
            if(iAmDead)
            {
                if (gate("girisKapi")->isConnected()) gate("girisKapi")->disconnect();
                if (gate("girisKapi2")->isConnected()) gate("girisKapi2")->disconnect();
                if (gate("cikisKapi")->isConnected()) gate("cikisKapi")->disconnect();
            }
        }
    }
}

void Node::finish()
{
    receivedRoundCountVector.record(globalRound); // Program tasarımında hata yapmışım, 5 cluster, yaklaşık bunun beşte biri olacak.
}



