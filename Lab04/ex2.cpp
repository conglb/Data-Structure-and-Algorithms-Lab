#include "etree.h"
#include "traversal.h"

using namespace std;

int main() {
	ETree* t = new ETree("(3+2*4)");
	Traversal* traversal = new Traversal();
	traversal->inorder(t->head);
	cout << endl;
	traversal->postorder(t->head);
	return 0;
}
