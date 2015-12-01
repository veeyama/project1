#include"STATUS.h"
#include"TERMINAL.h"
#include"BLE.h"
#include"BLESTATUS.h"
#include <vector>
#include <iostream>
#include<stdio.h>
#include<fstream>



using namespace std;
//BLE ble;
//TERMINAL term1;
int i;
int h;
extern int j;
extern double PV;
extern double S; 
extern double p;
extern double q;



vector<BLE> ble_box;
vector<vector<BLE>> ble_bigbox;




vector < TERMINAL > term_box;



BLESTATUS blestat;
STATUS status;

void show();
void log();


void main() {



	//TERMINALたち

	term_box.push_back(TERMINAL(0, 0));
	term_box.push_back(TERMINAL(1, 2));
	term_box.push_back(TERMINAL(3, 4));
	term_box.push_back(TERMINAL(5, 6));





	//BLEたち

	ble_box.push_back(BLE(1, 1));
	ble_box.push_back(BLE(7, 9));
	ble_box.push_back(BLE(12, 7));
	ble_box.push_back(BLE(1, 5));

	ble_bigbox.push_back(ble_box);

	ble_box.clear();


	ble_box.push_back(BLE(1540, 80));
	ble_box.push_back(BLE(5, 9));
	ble_box.push_back(BLE(12, 1));
	ble_box.push_back(BLE(7, 0));

	ble_bigbox.push_back(ble_box);

	ble_box.clear();


	ble_box.push_back(BLE(100, 8000));
	ble_box.push_back(BLE(7, 9));
	ble_box.push_back(BLE(12, 7));
	ble_box.push_back(BLE(7, 5));

	ble_bigbox.push_back(ble_box);

	ble_box.clear();

	ble_box.push_back(BLE(15050, 8000));
	ble_box.push_back(BLE(7, 99));
	ble_box.push_back(BLE(112, 7));
	ble_box.push_back(BLE(23, 123));

	ble_bigbox.push_back(ble_box);

	ble_box.clear();
	
	cout << "全BLE端末の座標を表示します" << endl;

	for (h = 0; h < 4; h++) {
		for (i = 0; i < 4; i++) {
			cout <<"("<< ble_bigbox[h][i].p <<","<< ble_bigbox[h][i].q <<")"<< endl;
		}
		}



		//cout << "ここまでOK" << endl;


		blestat.time = 0;


		//ofstream ofs("test.txt");




		while (blestat.time <1004312) {




			for (h = 0; h < 4; h++) {
				for (i = 0; i < 4; i++) {

					ble_bigbox[h][i].blecountdown();
					//cout << "ちん" << endl;

					ble_bigbox[h][i].blestatusIDchange();
					//cout << "ぱん" << endl;
				}
			}

			

			for (h = 0; h < 4; h++){
				term_box[h].statusIDchange();
			

			term_box[h].countdown();
			
		}





		//	log();

			show();



			blestat.time++;
		}



		system("pause");
	}


void show(){
	cout << "                                                TIME=" << blestat.time << "\n" << endl;

	for (i = 0; i <= 3; i++) {
	cout << "TERMINAL" << "[" << i << "] " << "STATUS=" << term_box[i].Status << "\t" << term_box[i].counter << endl;
	}

	for (h = 0; h <= 3; h++) {
		for (i = 0; i <= 3; i++) {

			cout << "BLE" << "[" << h << "] " << "[" << i << "] " << "STATUS=" << ble_bigbox[h][i].Statusble << "\t" << ble_bigbox[h][i].counter << "\t" << endl;
		}
	}
		cout << "--------------------------------------------------------\n";
	

}

/*void log() {
	ofstream ofs("test.txt", ios::app);

	ofs << "                               TIME=" << blestat.time << "\n" << endl;

	for (i = 0; i <= 3; i++) {
		ofs << "BLE" << "[" << i << "] " << "STATUS=" << ble_box[i].Statusble << "\t" << ble_box[i].counter << "\t" <<endl;

	}
	ofs << "TERMINAL" << "[" << 0 << "] " << "STATUS=" << term_box[0].Status << "\t" << term_box[0].counter << endl;



	ofs << "--------------------------------------------------------\n";


}*/