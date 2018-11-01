#include "slist.h"
#include <iostream>

using namespace std;

int main()
{
   SList<string>* dl = new SList<string>();
   string s1 = "111";
   SNode<string>* p = dl->addFirst(&s1);
   dl->print();

   string s2 = "222";
   dl->addFirst(&s2);
   dl->print();

   string s3 = "333";
   dl->addFirst(&s3);
   dl->print();

   string s4 = "444";
   dl->addFirst(&s4);
   dl->print();

   string s5 = "555";
   dl->addFirst(&s5);
   dl->print();

   dl->removeFirst();
   dl->print();
   dl->removeFirst();
   dl->print();
   dl->removeFirst();
   dl->print();

   return 0;
}
