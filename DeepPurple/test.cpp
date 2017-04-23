#include "Node.h"
int main() {
	Node node = Node();

	Node* children;
	int len = 3;
	for (int i = 0; i < len; i++) {
		children[i] = Node();
	}
	
	

	node.set_Children(children);

	Node* children3 = node.get_Children();
	printf("%d",children3[0].get_Draw());
	// asdasdasd
}