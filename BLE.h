#pragma once

#include <string>
#include <iostream>

using namespace std;

class BLE{

public:

	string BLE_NAME;

	// •Ï”
	double p;	// x•ûŒü‚ÌˆÊ’u
	double q;	// y•ûŒü‚ÌˆÊ’u

	double distance;

	string Statusble;	// Status‚ğ•\‚·
	int counter;	// ¡‚Ìó‘Ô‚ª‚ ‚Æ‰½usec‘±‚­‚©

					// ŠÖ”
	
	
	void blecountdown();
	void blestatusIDchange();
	

	BLE(double p,double q );
	~BLE();


private:


};

