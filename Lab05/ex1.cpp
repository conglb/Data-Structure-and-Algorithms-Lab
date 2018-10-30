/**
* Bubble sort in descending order
**/

#include <iostream>
#include <fstream>

using namespace std;

int n, a[100003];

int main() {
  ifstream in;
  ofstream out;
  in.open("exx1.inp");
  out.open("exx1.out");
  in >> n;
  for (int i=1; i<=n; i++) in >> a[i];
  for (int i=1; i<=n-1; i++) {
    for (int j=1; j<=n-i; j++) {
      if (a[j] < a[j+1]) swap(a[j], a[j+1]);
    }
  }
  for (int i=1; i<=n; i++) out << a[i] << " ";
  in.close(); out.close();
}
