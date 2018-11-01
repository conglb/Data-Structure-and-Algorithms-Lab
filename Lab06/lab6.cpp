#include <map>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Compare {
    bool operator()(const std::string& a, const std::string& b) const {
      for (int i=0; i<min(a.length(), b.length()); i++) {
        if (tolower(a[i]) != tolower(b[i])) return tolower(a[i]) < tolower(b[i]);
      }
      return a.length() < b.length();
    }
};

int main() {
  ifstream in;
  ofstream out;
  in.open("test.in");
  out.open("test.out");
  map<string, int, Compare> a;
  string s;
  in >> s;
  while (!in.eof()) {
    if (a.find(s) != a.end()) {
      a[s]++;
    } else {
      a.insert(make_pair(s, 1));
    }
    in >> s;
  }
  map<string, int>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    out << it->first << "\t\t" << it->second << endl;
  }
  in.close(); out.close();
  return 0;
}
