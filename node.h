/*
 * calculations.h
 *
 *  Created on: Dec 20, 2014
 *      Author: orhangazi44
 *
 *      LGPL
 *
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "leach_message_m.h"
#include <math.h>
#include <algorithm> // random_shuffle için

static int MIN_DISTANCE = -1;
static int SEND_REDUCE = 0;
static int RECEIVE_REDUCE = 1;
static int DATA_AGGREGATION_REDUCE = 2;
static int NO_DISTANCE = 3;
static int INFO = 0;
static int DATA = 1;
static int LEACH = 0;
static int IMPLEACH = 1;
static int CCRP = 2;
static int WSTLEACH = 3;
static int NUM_NODES;
static double E_ELEC;
static double E_AMP;
static double E_MP;
static double E_FS;
static int THRS_DIST;
int NUM_CLUSTERS;
int CLUSTER_DEFAULT_MEMBER;
int K;
double P;

static int ONCE = 1;
static int SONRA = 0;
static int NE_ONCE_NE_SONRA = -1;

class Node : public cSimpleModule
{
  private:
    cMessage *node2headDataMessage;
    cMessage *node2headChooseMessage;
    cMessage *ch2baseMessage;
    cMessage *waitEvent; // Kendine döndürecek
    cMessage *broadcastEvent; // Reklam mesajını bekletecek
    cMessage *littleBroadcastEvent; // Reklam mesajını bekletecek
    cMessage *headWaitEvent; // düğüm mesajını bekletecek
    cMessage *nextRoundEvent; // Sonraki round'a hazırlayacak
    cModule *server, *clusterHead, *mainModule;
    cOutVector receivedRoundCountVector;

    double chDistance, battery, fullBattery, networkRadius, dBS, aggBattery;
    double totalExpendedEnergy; // ch için;

    bool first_init = true;
    bool iAmHead = false;
    bool iAmDead = false;
    bool broadcastSent = false;
    bool littleBroadcastSent = false;
    bool chooseSent = false;
    bool noCh = false;
    bool broadcastArrived = false;
    std::string ch2headMsgStr = "";

    char *chFullPath = new char[128];
    char *color = new char[7];

    int xPosition, yPosition, curRound, globalRound, dieCount, clusterMemberCount = 0, gDeg, Nb = 0, range, algorithm;
    int * clusterMembers;
    int * clusterMemberXs;
    int * clusterMemberYs;

    int * posXs;
    int * posYs;

    cMessage * zincirEvent;
    cGate * cikisKapisi;
    int gelenMesajSayisiIlk, gelenMesajSayisiSon;
    int gonderilecekX, gonderilecekY;
    int gonderecekX, gonderecekY;
    int gonderecekX2, gonderecekY2; // Lider düğüm için, diğerleri kullanmayacak
    int liderNo = -1;
    int benimSiraNo;
    double * bataryalar; // Bataryalar ve düğüm listesini global tanımlayıp her düğümün erişebilmesi yerine Pegasis Algoritmasının Orijinalinde olduğu gibi her düğümün kendisinin hesaplaması sağladım
    int * chListesi; // Yasayan dugumlerin Listesiydi ilkin
    int * zincirDizi;
    double * bazaUzakliklar; // Düğümlerin baza uzaklıklarının dinamik tutulduğu dizi
    double ** dugumUzakliklari;
    bool * secilenler; // Düğümlerin Zincir için seçilip seçilmediklerini tutan dizi
    int * onceMiSonraMi;
    bool * olenler;
    bool liderim = false;
    bool baslangicim = false;
    bool sonum = false;
    int liderGelenMesajSayisi; // 2 ise yollasın diye
    bool ilk_baslangic = true;
    int bazX, bazY;
    int chSayisi; // Sonra bunun adını ch sayısı olarak değiştir

  protected:
    virtual void die();
    virtual void finish();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplayStringPositionAndTag(int x, int y);
    virtual void beginHeadSelection();
    virtual void beginNextRound();
    virtual double reduceBattery(double distance, int sendOrReduce, int type, int packetCount);
    virtual int getNodeId();
    virtual double treshold(int t_algorithm);

    virtual void zincirOlustur();
    virtual void bazaUzakliklariHesapla();
    virtual void dugumeUzakliklariHesapla(int dugumSiraNo);
    virtual int secilmemislerinEnYakini(int dugumSiraNo);
    virtual int getSiraId(int getid);
    virtual int getZincirSira(int getid);
    virtual int bazaEnUzagiBul();
    virtual int bazaEnYakiniBul();
};

double calculateDistance(int x0, int y0, int x1, int y1)
{
    return sqrt((double)( pow(abs(x0-x1), 2) + pow(abs(y0-y1), 2) ) );
}

char* generateRandomColor()
{
    char * color = new char[7];
    const char * hexa = "0123456789ABCDEF";
    color[0] = '#';
    color[1] = hexa[ intuniform(0, 15, 0) ];
    color[2] = hexa[ intuniform(0, 15, 1) ];
    color[3] = hexa[ intuniform(0, 15, 2) ];
    color[4] = hexa[ intuniform(0, 15, 3) ];
    color[5] = hexa[ intuniform(0, 15, 4) ];
    color[6] = hexa[ intuniform(0, 15, 5) ];
    return color;
}
#endif /* CALCULATIONS_H_ */
