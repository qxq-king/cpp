#pragma once
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int _size);
	Vector(const Vector& _vec);
	~Vector();
	void init(double value);
	int getsize();
	double getdata(int i);
	double& data(int i);
	double DotProduct(Vector& _vec);
	void print();
private:
	int    size;
	double* p_data;
};