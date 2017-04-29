#include <Python.h>
#include "Monte.h"


using namespace std;


int main(int argc, char* argv[])
{
	Py_Initialize();
	if (Py_IsInitialized()) {
		//Node* parent = new Node;
		//int len = 1000000;
		//Node** children = new Node*[len];
		//for (int i = 0; i < len; i++) {
		//	children[i] = new Node;
		//}
		//parent->set_Children(len,children);
		//parent->destroy();
		PyChess board = PyChess();
		board.printBoard();
		string choice = "";
		//cout << board.result() << endl;
		int a = 1;
		while (a==1) {
			a = 0;
			Monte monte = Monte(board);
			choice = monte.predict();
			cout << choice << endl;
		}
		cout << "asdasd" << endl;
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
		//string asd;
		//board.legal_moves();
		cout << "ending" << endl;
		while (true) {
			;
		}
		Py_Finalize();
	}
	return 0;
} 

