#include <BITS/stdc++.h>
using namespace std;

#include "mathematical.h"
#include "array.h"

#define rmscreen system("cls");

int main() {
	/*
	int n;
	cout << "����һ������";
	cin >> n;
	if (judge::number_prime(n)) { cout << "������\n"; }
	else { cout << "��������\n"; }
	
	rmscreen

	int a, b, re, rx;
	cout << "����������������";
	cin >> a >> b;
	re = arithmetic::number_divisor_max(a, b);
	rx = arithmetic::number_divisor_max_2(a, b);
	cout << "��С�������ǣ�" << re << ";���Լ���ǣ�" << a * b / re << endl;
	cout << "��С�������ǣ�" << rx << ";���Լ���ǣ�" << a * b / rx;
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