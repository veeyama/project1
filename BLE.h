#pragma once

#include <string>
#include <iostream>

using namespace std;

class BLE{

public:

	string BLE_NAME;

	// �ϐ�
	double p;	// x�����̈ʒu
	double q;	// y�����̈ʒu

	double distance;

	string Statusble;	// Status��\��
	int counter;	// ���̏�Ԃ����Ɖ�usec������

					// �֐�
	
	
	void blecountdown();
	void blestatusIDchange();
	

	BLE(double p,double q );
	~BLE();


private:


};

