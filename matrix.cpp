#include <bits/stdc++.h>
#include "matrix.h"

/*

	  _____                    _____                    _____                    _____                    _____                    _____                   _______                   _____                    _____
	 /\    \                  /\    \                  /\    \                  /\    \                  /\    \                  /\    \                 /::\    \                 /\    \                  /\    \
	/::\    \                /::\    \                /::\    \                /::\____\                /::\    \                /::\    \               /::::\    \               /::\    \                /::\____\
	\:::\    \              /::::\    \              /::::\    \              /::::|   |               /::::\    \              /::::\    \             /::::::\    \             /::::\    \              /::::|   |
	 \:::\    \            /::::::\    \            /::::::\    \            /:::::|   |              /::::::\    \            /::::::\    \           /::::::::\    \           /::::::\    \            /:::::|   |
	  \:::\    \          /:::/\:::\    \          /:::/\:::\    \          /::::::|   |             /:::/\:::\    \          /:::/\:::\    \         /:::/~~\:::\    \         /:::/\:::\    \          /::::::|   |
	   \:::\    \        /:::/__\:::\    \        /:::/__\:::\    \        /:::/|::|   |            /:::/__\:::\    \        /:::/__\:::\    \       /:::/    \:::\    \       /:::/__\:::\    \        /:::/|::|   |
	   /::::\    \      /::::\   \:::\    \      /::::\   \:::\    \      /:::/ |::|   |            \:::\   \:::\    \      /::::\   \:::\    \     /:::/    / \:::\    \     /::::\   \:::\    \      /:::/ |::|   |
	  /::::::\    \    /::::::\   \:::\    \    /::::::\   \:::\    \    /:::/  |::|   | _____    ___\:::\   \:::\    \    /::::::\   \:::\    \   /:::/____/   \:::\____\   /::::::\   \:::\    \    /:::/  |::|___|______
	 /:::/\:::\    \  /:::/\:::\   \:::\____\  /:::/\:::\   \:::\    \  /:::/   |::|   |/\    \  /\   \:::\   \:::\    \  /:::/\:::\   \:::\    \ |:::|    |     |:::|    | /:::/\:::\   \:::\____\  /:::/   |::::::::\    \
	/:::/  \:::\____\/:::/  \:::\   \:::|    |/:::/  \:::\   \:::\____\/:: /    |::|   /::\____\/::\   \:::\   \:::\____\/:::/  \:::\   \:::\____\|:::|____|     |:::|    |/:::/  \:::\   \:::|    |/:::/    |:::::::::\____\
   /:::/    \::/    /\::/   |::::\  /:::|____|\::/    \:::\  /:::/    /\::/    /|::|  /:::/    /\:::\   \:::\   \::/    /\::/    \:::\   \::/    / \:::\    \   /:::/    / \::/   |::::\  /:::|____|\::/    / ~~~~~/:::/    /
  /:::/    / \/____/  \/____|:::::\/:::/    /  \/____/ \:::\/:::/    /  \/____/ |::| /:::/    /  \:::\   \:::\   \/____/  \/____/ \:::\   \/____/   \:::\    \ /:::/    /   \/____|:::::\/:::/    /  \/____/      /:::/    /
 /:::/    /                 |:::::::::/    /            \::::::/    /           |::|/:::/    /    \:::\   \:::\    \               \:::\    \        \:::\    /:::/    /          |:::::::::/    /               /:::/    /
/:::/    /                  |::|\::::/    /              \::::/    /            |::::::/    /      \:::\   \:::\____\               \:::\____\        \:::\__/:::/    /           |::|\::::/    /               /:::/    /
\::/    /                   |::| \::/____/               /:::/    /             |:::::/    /        \:::\  /:::/    /                \::/    /         \::::::::/    /            |::| \::/____/               /:::/    /
 \/____/                    |::|  ~|                    /:::/    /              |::::/    /          \:::\/:::/    /                  \/____/           \::::::/    /             |::|  ~|                    /:::/    /
							|::|   |                   /:::/    /               /:::/    /            \::::::/    /                                      \::::/    /              |::|   |                   /:::/    /
							\::|   |                  /:::/    /               /:::/    /              \::::/    /                                        \::/____/               \::|   |                  /:::/    /
							 \:|   |                  \::/    /                \::/    /                \::/    /                                          ~~                      \:|   |                  \::/    /
							  \|___|                   \/____/                  \/____/                  \/____/                                                                    \|___|                   \/____/

*/

// ****************************************
// 函数名称: anti_arr_swap
// 函数功能: 交换二维动态数组的其中两行
// 参数传递: (float**)      操作的动态数组
//           (int)          交换的第一行, 
//           (int)          交换的第二行，
//           (unsigned int) 交换的列数
// 返 回 值: (void)
// ****************************************
void transform::anti_arr_swap(float** A, int y1, int y2, unsigned int nC) {
	float tmp;
	for (int j = 0; j < nC; j++) {
		tmp = A[y1][j];
		A[y1][j] = A[y2][j];
		A[y2][j] = A[y1][j];
	}
	return;
}

// ****************************************
// 函数名称：anti_arr_matrix_row_simp
// 函数功能：按行简化矩阵
// 参数传递：(float**)      操作的动态数组
//           (unsigned int) 交换的列数
//           (unsigned int) 交换的列数
// 返 回 值：(void)
// ****************************************
void transform::anti_arr_matrix_row_simp(float** A, unsigned int nR, unsigned int nC) {
	for (int j = 0; j < nR; j++) {
		int NoZeroCount = -1;
		if (fabs(A[j][j]) == 0) {
			NoZeroCount = 0;
			for (int i = j; i < nR; i++) {
				if (fabs(A[i][j]) != 0) {
					transform::anti_arr_swap(A, i, j, nC);
					NoZeroCount = i;
				}
			}
		}
		if (NoZeroCount != 0) {
			for (int i = j + 1; i < nR; i++) {
				float c = A[i][j] / A[j][j];
				for (int j1 = 0; j1 < nC; j1++) A[i][j1] = A[i][j1] - (A[j][j1] * c);
			}
		}
	}
	return;
}

/*

		  _____                    _____                    _____                _____                    _____                    _____                    _____                _____                    _____                    _____
		 /\    \                  /\    \                  /\    \              /\    \                  /\    \                  /\    \                  /\    \              /\    \                  /\    \                  /\    \
		/::\    \                /::\    \                /::\    \            /::\    \                /::\____\                /::\____\                /::\    \            /::\    \                /::\    \                /::\    \
	   /::::\    \              /::::\    \               \:::\    \           \:::\    \              /:::/    /               /::::|   |               /::::\    \           \:::\    \               \:::\    \              /::::\    \
	  /::::::\    \            /::::::\    \               \:::\    \           \:::\    \            /:::/    /               /:::::|   |              /::::::\    \           \:::\    \               \:::\    \            /::::::\    \
	 /:::/\:::\    \          /:::/\:::\    \               \:::\    \           \:::\    \          /:::/    /               /::::::|   |             /:::/\:::\    \           \:::\    \               \:::\    \          /:::/\:::\    \
	/:::/__\:::\    \        /:::/__\:::\    \               \:::\    \           \:::\    \        /:::/____/               /:::/|::|   |            /:::/__\:::\    \           \:::\    \               \:::\    \        /:::/  \:::\    \
   /::::\   \:::\    \      /::::\   \:::\    \              /::::\    \          /::::\    \      /::::\    \              /:::/ |::|   |           /::::\   \:::\    \          /::::\    \              /::::\    \      /:::/    \:::\    \
  /::::::\   \:::\    \    /::::::\   \:::\    \    ____    /::::::\    \        /::::::\    \    /::::::\    \   _____    /:::/  |::|___|______    /::::::\   \:::\    \        /::::::\    \    ____    /::::::\    \    /:::/    / \:::\    \
 /:::/\:::\   \:::\    \  /:::/\:::\   \:::\____\  /\   \  /:::/\:::\    \      /:::/\:::\    \  /:::/\:::\    \ /\    \  /:::/   |::::::::\    \  /:::/\:::\   \:::\    \      /:::/\:::\    \  /\   \  /:::/\:::\    \  /:::/    /   \:::\    \
/:::/  \:::\   \:::\____\/:::/  \:::\   \:::|    |/::\   \/:::/  \:::\____\    /:::/  \:::\____\/:::/  \:::\    /::\____\/:::/    |:::::::::\____\/:::/__\:::\   \:::\____\    /:::/  \:::\____\/::\   \/:::/  \:::\____\/:::/____/     \:::\____\
\::/    \:::\  /:::/    /\::/   |::::\  /:::|____|\:::\  /:::/    \::/    /   /:::/    \::/    /\::/    \:::\  /:::/    /\::/    / ~~~~~/:::/    /\:::\   \:::\   \::/    /   /:::/    \::/    /\:::\  /:::/    \::/    /\:::\    \      \::/    /
 \/____/ \:::\/:::/    /  \/____|:::::\/:::/    /  \:::\/:::/    / \/____/   /:::/    / \/____/  \/____/ \:::\/:::/    /  \/____/      /:::/    /  \:::\   \:::\   \/____/   /:::/    / \/____/  \:::\/:::/    / \/____/  \:::\    \      \/____/
		  \::::::/    /         |:::::::::/    /    \::::::/    /           /:::/    /                    \::::::/    /               /:::/    /    \:::\   \:::\    \      /:::/    /            \::::::/    /            \:::\    \
		   \::::/    /          |::|\::::/    /      \::::/____/           /:::/    /                      \::::/    /               /:::/    /      \:::\   \:::\____\    /:::/    /              \::::/____/              \:::\    \
		   /:::/    /           |::| \::/____/        \:::\    \           \::/    /                       /:::/    /               /:::/    /        \:::\   \::/    /    \::/    /                \:::\    \               \:::\    \
		  /:::/    /            |::|  ~|               \:::\    \           \/____/                       /:::/    /               /:::/    /          \:::\   \/____/      \/____/                  \:::\    \               \:::\    \
		 /:::/    /             |::|   |                \:::\    \                                       /:::/    /               /:::/    /            \:::\    \                                    \:::\    \               \:::\    \
		/:::/    /              \::|   |                 \:::\____\                                     /:::/    /               /:::/    /              \:::\____\                                    \:::\____\               \:::\____\
		\::/    /                \:|   |                  \::/    /                                     \::/    /                \::/    /                \::/    /                                     \::/    /                \::/    /
		 \/____/                  \|___|                   \/____/                                       \/____/                  \/____/                  \/____/                                       \/____/                  \/____/

*/

int arithmetic::anti_arr_matrix_rank(float** A, unsigned int nR, unsigned int nC) {
	int RB = 0;
	for (int i = 0; i < nR; i++) {
		for (int j = 0; j < nC; j++) {
			if (A[i][j] != 0) {
				RB += 1;
				break;
			}
		}
	}
	return RB;
}

/*
		  _____                    _____            _____                    _____                    _____
		 /\    \                  /\    \          /\    \                  /\    \                  /\    \
		/::\    \                /::\____\        /::\    \                /::\    \                /::\    \
	   /::::\    \              /:::/    /       /::::\    \              /::::\    \              /::::\    \
	  /::::::\    \            /:::/    /       /::::::\    \            /::::::\    \            /::::::\    \
	 /:::/\:::\    \          /:::/    /       /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \
	/:::/  \:::\    \        /:::/    /       /:::/__\:::\    \        /:::/__\:::\    \        /:::/__\:::\    \
   /:::/    \:::\    \      /:::/    /       /::::\   \:::\    \       \:::\   \:::\    \       \:::\   \:::\    \
  /:::/    / \:::\    \    /:::/    /       /::::::\   \:::\    \    ___\:::\   \:::\    \    ___\:::\   \:::\    \
 /:::/    /   \:::\    \  /:::/    /       /:::/\:::\   \:::\    \  /\   \:::\   \:::\    \  /\   \:::\   \:::\    \
/:::/____/     \:::\____\/:::/____/       /:::/  \:::\   \:::\____\/::\   \:::\   \:::\____\/::\   \:::\   \:::\____\
\:::\    \      \::/    /\:::\    \       \::/    \:::\  /:::/    /\:::\   \:::\   \::/    /\:::\   \:::\   \::/    /
 \:::\    \      \/____/  \:::\    \       \/____/ \:::\/:::/    /  \:::\   \:::\   \/____/  \:::\   \:::\   \/____/
  \:::\    \               \:::\    \               \::::::/    /    \:::\   \:::\    \       \:::\   \:::\    \
   \:::\    \               \:::\    \               \::::/    /      \:::\   \:::\____\       \:::\   \:::\____\
	\:::\    \               \:::\    \              /:::/    /        \:::\  /:::/    /        \:::\  /:::/    /
	 \:::\    \               \:::\    \            /:::/    /          \:::\/:::/    /          \:::\/:::/    /
	  \:::\    \               \:::\    \          /:::/    /            \::::::/    /            \::::::/    /
	   \:::\____\               \:::\____\        /:::/    /              \::::/    /              \::::/    /
		\::/    /                \::/    /        \::/    /                \::/    /                \::/    /
		 \/____/                  \/____/          \/____/                  \/____/                  \/____/

		  _____                    _____                _____                    _____                    _____
		 /\    \                  /\    \              /\    \                  /\    \                  /\    \                 ______
		/::\____\                /::\    \            /::\    \                /::\    \                /::\    \               |::|   |
	   /::::|   |               /::::\    \           \:::\    \              /::::\    \               \:::\    \              |::|   |
	  /:::::|   |              /::::::\    \           \:::\    \            /::::::\    \               \:::\    \             |::|   |
	 /::::::|   |             /:::/\:::\    \           \:::\    \          /:::/\:::\    \               \:::\    \            |::|   |
	/:::/|::|   |            /:::/__\:::\    \           \:::\    \        /:::/__\:::\    \               \:::\    \           |::|   |
   /:::/ |::|   |           /::::\   \:::\    \          /::::\    \      /::::\   \:::\    \              /::::\    \          |::|   |
  /:::/  |::|___|______    /::::::\   \:::\    \        /::::::\    \    /::::::\   \:::\    \    ____    /::::::\    \         |::|   |
 /:::/   |::::::::\    \  /:::/\:::\   \:::\    \      /:::/\:::\    \  /:::/\:::\   \:::\____\  /\   \  /:::/\:::\    \  ______|::|___|___ ____
/:::/    |:::::::::\____\/:::/  \:::\   \:::\____\    /:::/  \:::\____\/:::/  \:::\   \:::|    |/::\   \/:::/  \:::\____\|:::::::::::::::::|    |
\::/    / ~~~~~/:::/    /\::/    \:::\  /:::/    /   /:::/    \::/    /\::/   |::::\  /:::|____|\:::\  /:::/    \::/    /|:::::::::::::::::|____|
 \/____/      /:::/    /  \/____/ \:::\/:::/    /   /:::/    / \/____/  \/____|:::::\/:::/    /  \:::\/:::/    / \/____/  ~~~~~~|::|~~~|~~~
			 /:::/    /            \::::::/    /   /:::/    /                 |:::::::::/    /    \::::::/    /                 |::|   |
			/:::/    /              \::::/    /   /:::/    /                  |::|\::::/    /      \::::/____/                  |::|   |
		   /:::/    /               /:::/    /    \::/    /                   |::| \::/____/        \:::\    \                  |::|   |
		  /:::/    /               /:::/    /      \/____/                    |::|  ~|               \:::\    \                 |::|   |
		 /:::/    /               /:::/    /                                  |::|   |                \:::\    \                |::|   |
		/:::/    /               /:::/    /                                   \::|   |                 \:::\____\               |::|   |
		\::/    /                \::/    /                                     \:|   |                  \::/    /               |::|___|
		 \/____/                  \/____/                                       \|___|                   \/____/                 ~~

*/

//  ____  __  __  ____  __    ____   ___ 
// (  _ \(  )(  )(  _ \(  )  (_  _) / __)
//  ) __/ )(__)(  ) _ < )(__  _)(_ ( (__ 
// (__)  (______)(____/(____)(____) \___)
//

// **********
// 函数名称：Matrix
// 函数功能：创建类
// **********
Matrix::Matrix(int _row, int _col) {
	row = _row;
	col = _col;
	p_data = new double[row * col];
}

// **********
// 函数名称：Matrix
// 函数功能：从形参复制类
// **********
Matrix::Matrix(const Matrix& _ma) {
	row = _ma.row;
	col = _ma.col;
	p_data = new double[row * col];
	for (int j = 0; j < row * col; j++) {
		p_data[j] = _ma.p_data[j];
	}
}

// **********
// 函数名称：~Matrix
// 函数功能：析构函数
// **********
Matrix::~Matrix() {
	delete[] p_data;
	p_data = NULL;
}

// **********
// 函数名称：init
// 函数功能：以形参初始化 p_data
// **********
void Matrix::init(double value) {
	for (int i = 0; i < row * col; i++)
		p_data[i] = value;
}

// **********
// 函数名称：getdata
// 函数功能：返回 p_data[i] (向量第 i + 1 维的值)
// **********
double Matrix::getdata(int i, int j) {
	return p_data[i * col + j];
}

// **********
// 函数名称：data
// 函数功能：返回 p_data[i] (向量第 i + 1 维的值) 的引用
// **********
double& Matrix::data(int i, int j) {
	return p_data[i * col + j];
}

// **********
// 函数名称：multiply
// 函数功能：矩阵相乘，返回一个矩阵
// **********
Matrix Matrix::multiply(Matrix& _ma) {
	if (col != _ma.row) {
		cout << "\033[33m\033[41m\033[01mERR:\033[0m" << "Unexcepted size of two Matrix." << endl;
		Matrix ERR(1, 1);
		ERR.p_data[0] = 0;
		return ERR;
	}
	else {
		Matrix RT(row, _ma.col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < _ma.col; j++) {
				double sum = 0;
				for (int k = 0; k < col; k++) {
					sum += p_data[i * col + k] * _ma.p_data[k * _ma.row + i];
				}
				RT.p_data[i * _ma.col + j] = sum;
			}
		}
		return RT;
	}
}

// **********
// 函数名称：multiply2
// 函数功能：矩阵相乘，返回一个矩阵的引用
// **********
Matrix& Matrix::multiply2(Matrix& _ma) {
	if (col != _ma.row) {
		cout << "\033[33m\033[41m\033[01mERR:\033[0m" << "Unexcepted size of two Matrix." << endl;
		Matrix* ERR = new Matrix(1, 1);
		ERR->p_data[0] = 0;
		return*ERR;
	}
	else {
		Matrix* RT = new Matrix(row, _ma.col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < _ma.col; j++) {
				double sum = 0;
				for (int k = 0; k < col; k++) {
					sum += p_data[i * col + k] * _ma.p_data[k * _ma.row + i];
				}
				RT->p_data[i * _ma.col + j] = sum;
			}
		}
		return *RT;
	}
}

// **********
// 函数名称：multiply
// 函数功能：矩阵与向量相乘，返回一个向量
// **********
Vector& Matrix::multiply(Vector& _vec) {
	if (col != _vec.getsize())
		cout << "\033[33m\033[41m\033[01mERR:\033[0m" << "size is not correct!" << endl;
	Vector* c = new Vector(row);
	for (int i = 0; i < row; i++) {
		double sum = 0.;
		for (int j = 0; j < col; j++)
			sum += p_data[i * col + j] * _vec.data(j);
		c->data(i) = sum;
	}
	return *c;
}

// **********
// 函数名称：print
// 函数功能：输出矩阵
// **********
void Matrix::print() {
	cout << "\033[32mOutput matrix: \033[0m" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << p_data[i * col + j] << "  ";
		cout << endl;
	}
}
