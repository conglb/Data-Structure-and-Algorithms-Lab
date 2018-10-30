#include "traversal.h"

void Traversal::inorder(Node* head) {
	if (head == NULL) return;
	if (head->left != NULL) inorder(head->left);
	cout << head->value << " ";
	if (head->right != NULL) inorder(head->right);
}

void Traversal::postorder(Node* head) {
	if (head == NULL) return;
	if (head->left != NULL) postorder(head->left);
	if (head->right != NULL) postorder(head->right);
	cout << head->value << " ";
}