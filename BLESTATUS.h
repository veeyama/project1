#pragma once

#include <string>

using namespace std;

class BLESTATUS {

public:
	int time;

	int DataTime;  //�ް��𑗐M�ɂ����鎞��
	int OffTime;
	int INTERVAL_BLE_Time;
	int OffTimeFAILED;	//�|�[�����O��M���s���̓d���I�t���� 
	int R_POLLTime;
	int READYTime;
	int FIRSTTime;

	// ��Ԃ�\���ϐ�
	
	string BLESTATUS_OFF_FAILED = "BLE_OFF_FAILED";				//������OFF��ԁi�|�[�����O����M�ł��Ȃ������Ƃ��ɁA����ɑJ�ڂ���j
	string BLESTATUS_OFF = "BLE_OFF";		//�Z����OFF��ԁi�|�[�����O��M���f�[�^���M�ł����ꍇ�ɁA����ɑJ�ڂ���j
	string BLESTATUS_S_DATA = "BLE_Send_DATA";	//�f�[�^���M��
	string BLESTATUS_INTERVAL = "BLE_INTERVAL"; //SIFS
	string BLESTATUS_R_POLL = "BLE_R_POLL";	//�|�[�����O��M��
	string BLESTATUS_READY = "BLE_READY"; //WAIT���
	string BLESTATUS_FIRST = "BLE_FIRST_OFF";


	BLESTATUS();
	~BLESTATUS();

private:

}
;
