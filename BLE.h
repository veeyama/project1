#pragma once

#include <string>
#include <iostream>

using namespace std;

class BLE{

public:

	string BLE_NAME;

	// 変数
	double p;	// x方向の位置
	double q;	// y方向の位置

	double distance;

	string Statusble;	// Statusを表す
	int counter;	// 今の状態があと何usec続くか

					// 関数
	
	
	void blecountdown();
	void blestatusIDchange();
	

	BLE(double p,double q );
	~BLE();


private:


};

