#pragma once

#include <string>

using namespace std;

class BLESTATUS {

public:
	int time;

	int DataTime;  //ﾃﾞｰﾀを送信にかかる時間
	int OffTime;
	int INTERVAL_BLE_Time;
	int OffTimeFAILED;	//ポーリング受信失敗時の電源オフ時間 
	int R_POLLTime;
	int READYTime;
	int FIRSTTime;

	// 状態を表す変数
	
	string BLESTATUS_OFF_FAILED = "BLE_OFF_FAILED";				//長時間OFF状態（ポーリングが受信できなかったときに、これに遷移する）
	string BLESTATUS_OFF = "BLE_OFF";		//短時間OFF状態（ポーリング受信＆データ送信できた場合に、これに遷移する）
	string BLESTATUS_S_DATA = "BLE_Send_DATA";	//データ送信中
	string BLESTATUS_INTERVAL = "BLE_INTERVAL"; //SIFS
	string BLESTATUS_R_POLL = "BLE_R_POLL";	//ポーリング受信中
	string BLESTATUS_READY = "BLE_READY"; //WAIT状態
	string BLESTATUS_FIRST = "BLE_FIRST_OFF";


	BLESTATUS();
	~BLESTATUS();

private:

}
;
