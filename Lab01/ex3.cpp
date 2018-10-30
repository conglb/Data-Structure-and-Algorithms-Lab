#include <iostream>

using namespace std;

int a[1003];

void swapAll(int i, int j) {
	if (j > i) {
		swap(a[i], a[j]);
		swapAll(i+1,j-1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	int i, j;
	cin >> i >> j;
	swapAll(i,j);
	for (int i=1; i<=n; i++) cout << a[i] << " ";
	return 0;
}