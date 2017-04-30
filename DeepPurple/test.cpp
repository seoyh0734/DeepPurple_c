#include <Python.h>
#include "Monte.h"


using namespace std;

void make_children(Node* Parent,int Depth) {
	int child_num = 4;
	if (Depth > 0) {
	Node** children = new Node*[child_num];
		for (int i = 0; i < child_num; i++) {
			children[i] = new Node;
			make_children(children[i], Depth - 1);
		}
		Parent -> set_Children(child_num, children);
	}

}


int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	Py_Initialize();
	if (Py_IsInitialized()) {
		//Node* parent = new Node;
		//int len = 2;
		//make_children(parent, len);
		//parent->destroy();
	
		
		PyChess board = PyChess();
		board.push_san("e3");
		char* choice;
		int a = 1;
		while (a==1) {
			a = 0;
			Monte monte = Monte(board);
			choice = monte.predict();
		
			cout << choice << endl;
			monte.destroy();
		}
		//cout << "asdasd" << endl;
		////board.push_san(choice);
		////board.printBoard();
		//int node_num = 1000000;
		//Node** test = new Node*[node_num];
		//for (int i = 0; i < node_num; i++)
		//	test[i] = new Node;
		//for (int i = 0; i < node_num; i++)
		//	test[i]->destroy();
		//delete test;
		//char * choice = monte.predict();
		//cout << choice << endl;
		//char* asd;
		//board.legal_moves();
		cout << "ending" << endl;
		//board.destroy();
		while (true) {
			;
		}
		Py_Finalize();
	}
	return 0;
} 

