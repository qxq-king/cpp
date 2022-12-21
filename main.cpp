#include <BITS/stdc++.h>
using namespace std;

#include "mathematical.h"
#include "array.h"

#define rmscreen system("cls");

int main() {
	/*
	int n;
	cout << "输入一个数：";
	cin >> n;
	if (judge::number_prime(n)) { cout << "是素数\n"; }
	else { cout << "不是素数\n"; }
	
	rmscreen

	int a, b, re, rx;
	cout << "依次输入两个数：";
	cin >> a >> b;
	re = arithmetic::number_divisor_max(a, b);
	rx = arithmetic::number_divisor_max_2(a, b);
	cout << "最小公倍数是：" << re << ";最大公约数是：" << a * b / re << endl;
	cout << "最小公倍数是：" << rx << ";最大公约数是：" << a * b / rx;
	return 0;
	const int N = 10;

	int a[N] = { 1 };
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) { cout << a[i] << "\t"; }
	cout << endl;
	sort::selection(a, N);
	for (int i = 0; i < N; i++) { cout << a[i] << "\t"; }
	*/
	int a = 10;
	a += a *= a;
	cout << a;

}