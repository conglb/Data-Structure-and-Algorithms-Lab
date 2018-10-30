// http://www.cplusplus.com/reference/stl/stack/pop/
// stack::push/pop
#include <iostream>
#include <stack>
using namespace std;

int main ()
{
  stack<char> mystack;

  for (int i=0; i<5; ++i) mystack.push(char(i+'a'));

  cout << "Popping out elements...";
  while (!mystack.empty())
  {
     cout << " " << mystack.top();
     mystack.pop();
  }
  cout << endl;

  string s;
  getline(cin,s);
  bool check = 1;
  for (int i=0; i<s.size(); i++) {
    if (s[i] != '(') {
            if (mystack.empty()) {check = 0; break;}
            mystack.pop();
        } else mystack.push('(');
  }
    if (check && mystack.empty()) cout << "correct"; else cout << "wrong";
  return 0;
}
