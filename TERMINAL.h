#pragma once

#include <string>

using namespace std;

class TERMINAL{

public:
	//TERMINALのお名前

	string TERMINAL_NAME;



	// 変数
	double x;	// x方向の位置
	double y;	// y方向の位置
	double dist;


	double sigma;
	double mu;
	double z;
	double Ransu;
	double M_PI;
	double PV;




	int j;
	int q;

	string Status;	// Statusを表す
	int counter;	// 今の状態があと何usec続くか

	// 関数
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