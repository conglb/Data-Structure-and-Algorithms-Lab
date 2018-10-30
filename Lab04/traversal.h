#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include <iostream>
#include "etree.h"

using namespace std;

class Traversal {
	public:
		void inorder(Node* head);
		void postorder(Node* head);
};

#endif