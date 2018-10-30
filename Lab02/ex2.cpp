#include <iostream>
#include <stdio.h>

using namespace std;

int n;
bool x[10003];

void printResult() {
	for (int i=1; i<=n; i++) 
		if (x[i]) cout << i << " ";
	cout << endl;
}

void attempt(int i) {
	for (int j=0; j<=1; j++) {
		x[i] = j;
		if (i == n) printResult(); else attempt(i+1); 
	}
}
int main() {
	cin >> n;
	attempt(1);
	return 0;
}