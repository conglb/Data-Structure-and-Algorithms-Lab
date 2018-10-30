#include <fstream>

using namespace std;

int n, a[10003];

int main() {
  ifstream in;
  ofstream out;
  in.open("exx2.inp");
  out.open("exx2.out");
  in >> n;
  for (int i=1; i<=n; i++) in >> a[i];
  for (int i=2; i<=n; i++) {
    for (int j=i-1; j>=1; j--) {
      if (a[j+1] < a[j]) swap(a[j+1], a[j]); else break;
    }
  }
  for (int i=1; i<=n; i++) out << a[i] << " ";
  in.close(); out.close();
  return 0;
}
