#pragma once

#include <string>

using namespace std;

class TERMINAL{

public:
	//TERMINAL�̂����O

	string TERMINAL_NAME;



	// �ϐ�
	double x;	// x�����̈ʒu
	double y;	// y�����̈ʒu
	double dist;


	double sigma;
	double mu;
	double z;
	double Ransu;
	double M_PI;
	double PV;




	int j;
	int q;

	string Status;	// Status��\��
	int counter;	// ���̏�Ԃ����Ɖ�usec������

	// �֐�
	void test();
	void move();
	void countdown();
	void statusIDchange();
	void gaussrand();
	double Uniform();


	TERMINAL(double x, double y);
	~TERMINAL();


private:


};