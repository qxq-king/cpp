#include <bits/stdc++.h>
#include "matrix.h"


// ****************************************
// 函数名称: anti_arr_swap
// 函数功能: 交换二维动态数组的其中两行
// 参数传递: (float**)      操作的动态数组
//           (int)          交换的第一行, 
//           (int)          交换的第二行，
//           (unsigned int) 交换的列数
// 返 回 值: (void)
// 注意事项: 函数传递的二维数组为二级指针类动态数组
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
// 注意事项：函数传递的二维数组为二级指针类动态数组
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
