#pragma once
#include "vector.h"
namespace transform {
	void anti_arr_swap(float**, int, int, unsigned int);
	void anti_arr_matrix_row_simp(float**, unsigned int, unsigned int);
}

namespace arithmetic {
	int  anti_arr_matrix_rank(float**, unsigned int, unsigned int);
}

using namespace std;




class Matrix {
public:
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	void init(double);
	double getdata(int, int);
	double& data(int, int);
	Matrix multiply(Matrix&);
	Matrix& multiply2(Matrix&);
	Vector& multiply(Vector&);
	void print();
private:
	int row, col;
	double* p_data;
};