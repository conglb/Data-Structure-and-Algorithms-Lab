#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1003;
int a[1003], ans, n;
bool x[1003], y[1003];
stack<int> s;

void update() {
	int dem = 0;
	for (int i=1; i<=n; i++)
		if (x[i] == 1) dem++;
	if (dem > ans) {
		ans = dem;
		for (int i=1; i<=n; i++) y[i] = x[i];
	}
}

void attempt(int i) {

	for (int j=1; j>=0; j--) {
		if (j == 1 && (s.empty() || a[i] >= s.top())) {
			x[i] = 1;
			s.push(a[i]);
		} else {
			x[i] = 0;
		}
		if (i  == n) update(); else attempt(i+1);
		if (x[i] == 1) {
			s.pop();
		}
	}

}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	attempt(1);
	for (int i=1; i<=n; i++)
		if (y[i]) cout << a[i] << " ";
	return 0;
}