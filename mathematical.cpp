#include <BITS/stdc++.h>
#include "mathematical.h"
#include "base.h"

bool judge::number_prime(int n){
	if (n <= 1) { return false; }
	else {
		for (int i = 1; i < n; i++) {
			if (n % i == 0) return true;
		}
	}
	return false;
}

int arithmetic::number_divisor_max(int a, int b){
	int rt = 1;
	if (a <= 1 || b <= 1) { return 0; }
	else {
		for (int i = 2; i <= a && i <= b; i++) {
			if (a % i == 0 && b % i == 0) { rt = i; }
		}
	}
	return rt;
}

int arithmetic::number_divisor_max_2(int u, int v){
	if (u < v)swap(&u, &v);
	int r = u % v;
	while (r!=0){
		u = v, v = r;
		r = u % v;
	}
	return v;
}
// rt ·µ»ØÖµ
// 
//
