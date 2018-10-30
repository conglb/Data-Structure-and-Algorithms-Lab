#ifndef ETREE_H_INCLUDED
#define ETREE_H_INCLUDED
#include <iostream>
#include <stack>

using namespace std;

class Node {
	public:
		int value;
		Node * left, * right;
		Node(int v) {
			value = v;
			left = NULL;
			right = NULL;
		}

		int getValue() {
			return value;
		}
};

class ETree {
	public:
		Node* head;
		void setHead(Node* node) {
			head = node;
		}

		bool isOperator(char c) {
			return (c == '+' || c == '-' || c == '*' || c == '/');
		}


		bool isBracket(char c) {
			return (c == '(' || c == ')');
		}

		int decode(char c) {
		    if (c == '(') return -1;
		    if (c == ')') return -2;
			if (c == '+') return 1;
			if (c == '-') return 2;
			if (c == '*') return 3;
			if (c == '/') return 4;
			return (c - '0');
		}

		ETree(string s) {
			stack<Node*> a;
			for (int i=0; i<s.size(); i++) {
				//if (i==4)while (!a.empty()){cout << a.top() <<endl; a.pop();}
				if (isOperator(s[i])) {
                    Node* tmp = new Node(decode(s[i]));
					a.push(tmp);
				} else
				if (isBracket(s[i])) {
					if (s[i] == '(') {
						Node* tmp = new Node(decode(s[i]));
                        a.push(tmp);
					}
					else {
                        Node* n1, *n2, *n3;
                        while (!a.empty() && (a.top()->value != -1)) {
							n1 = a.top(); a.pop();
							n2 = a.top(); a.pop();
							n3 = a.top(); a.pop();
							n2->left = n1;
							n2->right = n3;
						}
						if (!a.empty()) a.pop(); // pop (
                        a.push(n2);
					}
				} else {
					if ((!a.empty()) &&
         (s[i-1]=='*'  || s[i-1]=='/')
         //(a.top()->value == 3 || a.top()->value == 4)

         ) {
						a.pop();
						int tmp = a.top()->value * decode(s[i]);
                        Node* n1 = new Node(a.top()->value);
                        Node* n2 = new Node(decode(s[i-1]));
                        Node* n3 = new Node(decode(s[i]));
                        n2->left = n1;
                        n2->right = n3;
						a.pop();
						a.push(n2);
					} else
						a.push(new Node(decode(s[i])));
				}
			}
			head = a.top();
		}
};

#endif // ETREE_H_INCLUDED
