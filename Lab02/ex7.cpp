#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
struct SNode {
   string* element;
   SNode *next; // Pointer to the next node 
   SNode *prev; // Pointer to the previous node

   /* Creates a node. */
   SNode(string* e, SNode* n, SNode* m)  {
      element = e;
      next = n;
      prev = m;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

class SList {
protected:		// data member
    SNode* head;	
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    SList() {
        head = NULL;
        size = 0;
    }
    ~SList() {
  
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }
    SNode* getHead() { return head; }

    // add a new node to the begining of the list
    SNode* addFirst(string* s) {
        SNode* newNode = new SNode(s, head, NULL);
        head = newNode;
        size++;
        return newNode;
    }

    //remove the first node in the list
    string* removeFirst() {
        if (head==NULL) return NULL;
        head = head->next;
        head->prev = NULL;
        string* s = head->element;
        return s;
    }

    // insert a new node after node n and store the string s there
    void insertAfter (SNode* n, string* s) {
        if (n == NULL) return;
        SNode* newNode = new SNode(s, n->next, n);
        n->next = newNode;
    }

    void deleteAfter (SNode* n) {
        if (n == NULL) return;
        if (n->next == NULL) return;
        SNode* tmp = n->next;
        n->next = tmp->next;
        tmp->next->prev = n;
    }

    // delete node n and return the string stored in n
    string* insertAfter (SNode* n) {
        if (n == NULL) return NULL;
        if (head == n) {
            this->removeFirst();
            return n->element;
        }
        SNode* pre = NULL;
        SNode* cur = head;
        while (cur != NULL) {
            if (cur == n) {
                deleteAfter(pre);
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return n->element;
    }

    //display the list's data in order from head to tail
    void print() {
        SNode* iter = head;
        while (iter!=NULL) {
            // call SNode method to display iter's data
            //.....
            cout << *iter->element << " ";
            iter = iter->next;   
        }
        cout << endl << "------" << endl;
    }  
};

int main(void)
{
   // You should modified this function to test list's methods.

   SList* dl = new SList();
   string s1 = "1";
   SNode* p = dl->addFirst(&s1);
   dl->print();

   string s2 = "2";
   dl->addFirst(&s2);
   dl->print();

   string s3 = "3";
   dl->addFirst(&s3);
   dl->print();

   string s4 = "4";
   dl->addFirst(&s4);
   dl->print();

   string s5 = "5";
   dl->addFirst(&s5);
   dl->print();

   dl->removeFirst();
   dl->print();
   dl->removeFirst();
   dl->print();
   dl->insertAfter(dl->getHead());
   dl->print();

   return 0;
}