#include <iostream>
#include <stdio.h>

using namespace std;

int calc(int m, int n) {
	if (n == 0) return 0;
	return m + calc(m, n-1);
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << calc(m,n);
	return 0;
}