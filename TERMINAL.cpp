#include "TERMINAL.h"
#include "STATUS.h"
#include "BLESTATUS.h"
#include"BLE.h"

#include <iostream>
#include<vector>
#include<math.h>
#include <ctime> // for time()
#include <cstdlib> // for srand(), rand()






extern STATUS status;
extern vector <vector <BLE>> ble_bigbox;
extern BLESTATUS blestat;
extern vector<TERMINAL> term_box;
using namespace std;

extern int i;
extern int j;
int k;
extern int h;
/*double p;
double q;
double R;
int MIN;
int MAX;

double PV;
*/
void TERMINAL::test(){

	x = x + 10.0;
	y = y + 20.0;

}

void TERMINAL::gaussrand()
{


	
	
	mu = 0;
	sigma = 3.8;
	M_PI = 3.141592;

	double z = sqrt(-2.0*log(Uniform())) * sin(2.0*M_PI*Uniform());
	Ransu = mu + sigma*z;



}

double TERMINAL::Uniform(void)
{
	static int x = 10;
	int a = 1103515245;
	int b = 12345;
	int c = 2147483647;
	x = (a*x + b)&c;

	return ((double)x + 1.0) / ((double)c + 2.0);
}


void TERMINAL::move(){

	// 1usecにx方向に0.00001m動くとしとく
	x = x + 0.00001;

}

void TERMINAL::countdown(){

	this->counter--;



}


void TERMINAL::statusIDchange() {

	

		if (counter == 0) {

			//cout << "いまのhは" << h << "ですよん" << endl;

			if (Status == status.STATUS_OFF) {

				Status = status.STATUS_POLL;

				counter = status.PollTime;

				for (j = 0; j <4;j++) {
					//cout << "いまのjは" << j << "ですよん" << endl;
					if (ble_bigbox[h][j].Statusble == blestat.BLESTATUS_READY)
					{
						//cout << "いまのjは" << j << "ですよん２" << endl;
						gaussrand();
						cout << "READY状態にあるBLEの座標(" << ble_bigbox[h][j].p << "," << ble_bigbox[h][j].q <<")"<< endl;
						cout << "それが接続するTERMINALの座標(" << term_box[h].x << "," << term_box[h].y << ")" << endl;
						double dist = pow((((ble_bigbox[h][j].p * ble_bigbox[h][j].p)-(term_box[h].x * term_box[h].x)) + ((ble_bigbox[h][j].q * ble_bigbox[h][j].q) - (term_box[h].y * term_box[h].y))), 0.5);
						PV = -46.1 - 6.6* log10(dist) - (double)Ransu;

						cout << "雑音(dB)は" << Ransu << endl;

						cout << "受信電力は" << PV <<"dB"<< endl;
						cout << "距離は" << dist/10 <<"cm"<< endl;



						if (PV >= -70) {
							ble_bigbox[h][j].Statusble = blestat.BLESTATUS_R_POLL;
							ble_bigbox[h][j].counter = 239;
							cout << h << "," << j << "番のポーリング成功" << endl;
							cout << "-------------------\n";
						}
						else if (PV < -70) {
							cout << h << "," << j << "番のポーリング失敗" << endl;
							cout << "-------------------\n";
						}
						
					}
					
				}
			}

				/*
				if (ble_bigbox[0][j % 4].Statusble == blestat.BLESTATUS_READY)
				{
					k = 0;
					gaussrand();
					cout << "pとq" << ble_bigbox[k][j % 4].p << "," << ble_bigbox[k][j % 4].q << endl;
					double dist = pow((ble_bigbox[k][j % 4].p * ble_bigbox[k][j % 4].p + ble_bigbox[k][j % 4].q*ble_bigbox[k][j % 4].q), 0.5);
					PV = -46.1 - 6.6* log10(dist) - (double)Ransu;

					cout << "受信電力PVは" << PV << endl;
					cout << "距離は" << dist << endl;



					if (PV >= -70) {
						ble_bigbox[k][j % 4].Statusble = blestat.BLESTATUS_R_POLL;
						ble_bigbox[k][j % 4].counter = 239;
						cout <<k<<","<<j%4<< "番のポーリング成功" << endl;
						
						j = j + 1;
						
					}
					else {

						cout << k << "," << j % 4 << "番のポーリングがとどきませんでした" << endl;
						j = j + 1;
					}

					cout << "あ" << endl;
				}
				

				if (ble_bigbox[1][j % 4].Statusble == blestat.BLESTATUS_READY)
				{
					k = 1;
					gaussrand();
					cout << "pとq" << ble_bigbox[k][j % 4].p << "," << ble_bigbox[k][j % 4].q << endl;
					double dist = pow((ble_bigbox[k][j % 4].p * ble_bigbox[k][j % 4].p + ble_bigbox[k][j % 4].q*ble_bigbox[k][j % 4].q), 0.5);
					PV = -46.1 - 6.6* log10(dist) - (double)Ransu;

					cout << "受信電力PVは" << PV << endl;
					cout << "距離は" << dist << endl;



					if (PV >= -70) {
						ble_bigbox[k][j % 4].Statusble = blestat.BLESTATUS_R_POLL;
						ble_bigbox[k][j % 4].counter = 239;

						cout << k << "," <<j%4<< "番のポーリング成功" << endl;
						j = j + 1;

						
					}
					else {
						

						cout << k << "," << j % 4 << "番のポーリングがとどきませんでした" << endl;
						j = j + 1;
					}
					cout << "い" << endl;
				}

				if (ble_bigbox[2][j % 4].Statusble == blestat.BLESTATUS_READY)
				{
					k = 2;
					gaussrand();
					cout << "pとq" << ble_bigbox[k][j % 4].p << "," << ble_bigbox[k][j % 4].q << endl;
					double dist = pow((ble_bigbox[k][j % 4].p * ble_bigbox[k][j % 4].p + ble_bigbox[k][j % 4].q*ble_bigbox[k][j % 4].q), 0.5);
					PV = -46.1 - 6.6* log10(dist) - (double)Ransu;

					cout << "受信電力PVは" << PV << endl;
					cout << "距離は" << dist << endl;



					if (PV >= -70) {
						ble_bigbox[k][j % 4].Statusble = blestat.BLESTATUS_R_POLL;
						ble_bigbox[k][j % 4].counter = 239;
						cout << k << "," << j % 4 << "番のポーリング成功" << endl;
						j = j + 1;
					
					}
					else {

						cout << k << "," << j % 4 << "番のポーリングがとどきませんでした" << endl;
						j = j + 1;
					}
					cout << "う" << endl;
				}

				if (ble_bigbox[3][j % 4].Statusble == blestat.BLESTATUS_READY)
				{
					k = 3;
					gaussrand();
					cout << "pとq" << ble_bigbox[k][j % 4].p << "," << ble_bigbox[k][j % 4].q << endl;
					double dist = pow((ble_bigbox[k][j % 4].p * ble_bigbox[k][j % 4].p + ble_bigbox[k][j % 4].q*ble_bigbox[k][j % 4].q), 0.5);
					PV = -46.1 - 6.6* log10(dist) - (double)Ransu;

					cout << "受信電力PVは" << PV << endl;
					cout << "距離は" << dist << endl;



					if (PV >= -70) {
						ble_bigbox[k][j % 4].Statusble = blestat.BLESTATUS_R_POLL;
						ble_bigbox[k][j % 4].counter = 239;
						cout << k << "," << j % 4 << "番のポーリング成功" << endl;
						j = j + 1;
					
					}
					else {

						cout << k << "," << j % 4 << "番のポーリングがとどきませんでした" << endl;
						j = j + 1;
					}
					cout << "え" << endl;
				}

				else {
					cout << "だめ" << endl;
		
				}
				
				*/

				/*else if(ble_bigbox[k][j % 4].Statusble != blestat.BLESTATUS_READY)
				{
					cout << "ターミナルがBLEのステータスを変更しようとしたが、" <<k<<","<< j % 3 << "のBLEの状態がREADYじゃないっぽい的なエラー" << endl;


					system("pause");
				}
				*/


			

			else if (Status == status.STATUS_POLL) {
				Status = status.STATUS_INTERVAL;
				counter = status.IntervalTime;



			}

			else if (Status == status.STATUS_INTERVAL) {
				Status = status.STATUS_R_DATA;
				counter = status.DATATime;



			}

			else if (Status == status.STATUS_R_DATA)
			{
				if (q % 4 == 0) {

					Status = status.STATUS_OFF;
					counter = 100;

					ble_bigbox[h][0].counter = 80;
					ble_bigbox[h][1].counter = 1330;
					ble_bigbox[h][2].counter = 2580;
					ble_bigbox[h][3].counter = 3830;

					blestat.time = blestat.time + 999900/4;
					/*時間加算の方法は、暫定的なものであり、今後の修正事項である*/
					cout << "blestat.timeに999900÷4を足しました"<< endl;
					q = q + 1;
				}

				else {
					Status = status.STATUS_OFF;
					counter = status.OFFTime;
					q = q + 1;

				}
			}



			else {
				cout << "error" << endl;
			}
		}

		else {

			//cout << "まだterminalはのこりじかんある　つづく" << endl;


		}


	
}



TERMINAL::TERMINAL(double x, double y){
	
	this->x = x;
	this->y = y;

	this->Status = "OFF";
	this->counter = 30;

	this->j = 0;
	this->q = 1;
}

TERMINAL::~TERMINAL(){}