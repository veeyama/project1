#include "BLE.h"
#include "BLESTATUS.h"
#include"TERMINAL.h"
#include"STATUS.h"

#include <iostream>
#include<vector>
#include <math.h>

extern BLESTATUS blestat;
extern vector<TERMINAL> term_box;

using namespace std;


extern int i;



void BLE::blecountdown() {

	this->counter--;



}

void BLE::blestatusIDchange() {

	if (counter == 0) {

		if (Statusble == blestat.BLESTATUS_OFF) {
		Statusble = blestat.BLESTATUS_READY;
		counter = blestat.READYTime;

		cout << "off to ready" << endl;
	}
		else if (Statusble == blestat.BLESTATUS_READY) {
			Statusble = blestat.BLESTATUS_OFF;
			counter = blestat.OffTimeFAILED;

			cout << "ready to off failed" << endl;

		}

		else if (Statusble == blestat.BLESTATUS_FIRST) {
			Statusble = blestat.BLESTATUS_READY;
			counter = blestat.READYTime;


			cout << "offfirst-ready" << endl;
		}
		
	

		else if (Statusble == blestat.BLESTATUS_R_POLL) {
			Statusble = blestat.BLESTATUS_INTERVAL;
			counter = blestat.INTERVAL_BLE_Time;

			cout << "rpoll to interval" << endl;
		}

		else if (Statusble == blestat.BLESTATUS_INTERVAL) {
			Statusble = blestat.BLESTATUS_S_DATA;
			counter = blestat.DataTime;

			cout << "interval@to sdata" << endl;
		}

		else if(Statusble == blestat.BLESTATUS_S_DATA) {
			Statusble = blestat.BLESTATUS_OFF;
			counter = blestat.OffTime;
			cout << "sdata to off" << endl;

		}





		else {
			cout << "error" << endl;
		}
	}

	else {



	}


}



BLE::BLE(double p, double q) {

	this->p = p;
	this->q = q;





	this->Statusble = "BLE_FIRST_OFF";
	this->counter = 10 + 1250 * (i % 4);

	i = i + 1;

}

BLE::~BLE() {}