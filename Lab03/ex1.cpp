#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
struct SNode {
   string* element;
   SNode *next; // Pointer to the next node

   /* Creates a node. */
   SNode(string* e, SNode* n)  {
      element = e;
      next = n;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

class Stack {
protected:		// data member
    SNode* head;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    Stack() {
        head = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    SNode* push(string* s) {
        SNode* newNode = new SNode(s, head);
        head = newNode;
        size++;
        return newNode;
    }
    string* pop() {
        if (head==NULL) return NULL;
        string* s = head->element;
        SNode * t = head;
        head = head->next;
        delete t;
        size--;
        return s;
    }

    void print() {
        SNode* iter = head;
        string* a[size+1];
        int i = 0;
        while (iter!=NULL) {
            a[i] = iter->element;
            iter = iter->next;
            i++;
        }
        for (int i=size-1; i>=0; i--) cout << *a[i] << " ";
        cout << endl;
    }
};

int main(void)
{
   Stack* dl = new Stack();
   string s1 = "1";
   SNode* p = dl->push(&s1);
   dl->print();

   string s2 = "2";
   dl->push(&s2);
   dl->print();

   string s3 = "3";
   dl->push(&s3);
   dl->print();

   string s4 = "4";
   dl->push(&s4);
   dl->print();

   string s5 = "5";
   dl->push(&s5);
   dl->print();

   dl->pop();
   dl->print();
   dl->pop();
   dl->print();
   dl->pop();
   dl->print();

   return 0;
}
