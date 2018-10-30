#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* Node of a singly linked list of strings */
class AList {
protected:	
    int* a;	// dynamically allocated array of ints
    long maxSize, size;	// logic size of the array(not the allocated size)

public:
    /* Default constructor that creates an empty list */
    AList(int maxSize) {
        this->maxSize =maxSize;
        a = new int[maxSize];
        size = 0;
    }
    //clean up all the memory that has been allocated in the constructor.
    ~AList() {
        delete a;    
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }
    int isFull() { 
       return size == maxSize;
    }

    //add a number to the end of the array
    //return index of the new entry
    //do nothing and return -1 if the array is already full
    int addLast(int n) {
        // your implementation
        if (this->isFull()) return -1;
        size++;
        a[size-1] = n;
        return size;
    }
    
    //insert a number to the entry indexed i in the array
    // if i is too big (>size) then add the new entry to the end instead
    // do nothing if the array is already full
    void insert(int n, int i) {
        // your implementation
        if (this->isFull()) return;
        if (i >= size) i = size;
        for (int j=size-1; j>=i; j--) {
            a[j+1] = a[j];
        }
        a[i] = n;
        size++;
    }

    //remove entry with index i, shift all entries from i+1 to the left
    // do nothing if there is no entry i
    int removeIndex(int i) {
        // your implementation
        if (i > size-1 || i < 0) return 0;
        for (int j = i; j <= size-2; j++) {
            a[j] = a[j+1];
        }
        size--;
        return 1;
    }

    //remove all the entries with value n, 
    // shift entries to the left to cover the deleted slots.
    int removeData(int n) {
        // your implementation
        for (int i=0; i<size; i++) 
            if (a[i] == n) removeIndex(i);
        return 1;
    }

    //display the array's data in order 
    void print() {
        cout << this->size << endl;
        for (int i=0; i<size; i++) {
            cout << this->a[i] << " ";
        }
        cout << endl;
    }  
};

int main(void)
{
   // your code to test class AList
    AList* a = new AList(5);
    a->addLast(1);
    a->addLast(10);
    a->print();
    a->addLast(8);
    a->print();
    a->insert(7,1);
    a->insert(11,0);
    a->removeData(11);
    a->print();
    a->removeData(8);
    a->print();
   return 0;
}