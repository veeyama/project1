#pragma once

#include <string>

using namespace std;

class STATUS{

public:

	int time;	// �V�~�����[�V�����̌o�ߎ���(usec)

	int PollTime;
	int IntervalTime;
	int OFFTime;
	int DATATime;
	int OFFTimeLONG;

	// ��Ԃ�\���ϐ�
	string STATUS_INTERVAL = "INTERVAL";
	string STATUS_POLL = "POLL";
	string STATUS_R_DATA = "R_DATA";
	string STATUS_OFF = "OFF";


	STATUS();
	~STATUS();

private:


};