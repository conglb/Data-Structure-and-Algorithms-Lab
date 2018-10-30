#include <string>
#include <iostream>

#include "slist.h"

using namespace std;

class Queue {
private:
    SList* slist;

public:
    Queue() { slist = new SList(); }
    bool isEmpty() { return slist->isEmpty(); }
    long getSize() { return slist->getSize(); }
    void push(string* s) {
        slist->addFirst(s);
    }
    string* pop() {
        //your code goes here
        slist->removeLast();
    }
    string* top() {
        //your code goes here
        slist->getLast();
    }
    void reverse() {
        int n = slist->getSize();
        string* a[n+3];
        for (int i=1; i<=n; i++) {a[i] = slist->removeFirst();}
        for (int i=1; i<=n; i++) {push(a[i]);}
    }
    void print() { slist->print(); }
};

int main()
{
    Queue* s = new Queue();
    string s1 = "1", s2 = "2", s3 = "3", s4 = "4";

    s->push(&s1);
    s->print();
    s->push(&s2);
    s->print();
    s->push(&s3);
    s->print();
    s->push(&s4);
    s->print();
    cout << "pop: "<< *(s->pop()) << endl;
    s->print();
    s->reverse();
    s->print();

    return 0;
}
