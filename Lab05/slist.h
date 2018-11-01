#ifndef __SLIST_H
#define __SLIST_H

#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
template <typename T>
struct SNode {
   T* element;
   SNode *next; // Pointer to the next node

   /* Creates a node. */
   SNode(T* e, SNode* n)  {
      element = e;
      next = n;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

template <typename E>
class SList {
protected:		// data member
    SNode<E>* head;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    SList() {
        head = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    SNode<E>* addFirst(E* s) {
        SNode<E>* newNode = new SNode<E>(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    string* removeFirst() {
        if (head==NULL) return NULL;
        E* s = head->element;
        SNode<E>* t = head;
        head = head->next;
        delete t;
        size--;
        return s;
    }

    E* getLast() {
        if (head == NULL) return NULL;
        SNode<E>* cur = head;
        while (cur != NULL) {
            cur = cur->next;
        }
        return cur->element;
    }

    E* removeLast() {
        if (head == NULL) return NULL;
        if (size == 1) {
            E* res = head->element;
            head == NULL;
            return res;
        }
        SNode<E>* cur = head;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }
        E* res = cur->next->element;
        delete cur->next;
        size--;
        cur->next = NULL;
        return res;
    }

    void print() {
        SNode<E>* iter = head;
        while (iter!=NULL) {
            iter->print();
            cout << ", ";
            iter = iter->next;
        }
        cout << endl;
    }
};

/* sample client/text code
int main(void)
{
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
   dl->removeFirst();
   dl->print();

   return 0;
}
*/
#endif
