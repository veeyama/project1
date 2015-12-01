#pragma once

#include <string>

using namespace std;

class STATUS{

public:

	int time;	// シミュレーションの経過時間(usec)

	int PollTime;
	int IntervalTime;
	int OFFTime;
	int DATATime;
	int OFFTimeLONG;

	// 状態を表す変数
	string STATUS_INTERVAL = "INTERVAL";
	string STATUS_POLL = "POLL";
	string STATUS_R_DATA = "R_DATA";
	string STATUS_OFF = "OFF";


	STATUS();
	~STATUS();

private:


};