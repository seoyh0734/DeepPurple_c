#include <Python.h>
#include <iostream>
#include "PyChess.h"
#include <string>

using namespace std;


//#include "PyChess.h"


void printBoard(PyObject* object) {
	PyObject* pValue = PyObject_CallMethod(object, "print_board", NULL, NULL);
};

int main(int argc, char* argv[])
{
	Py_Initialize(); // √ ±‚»≠ 
	PyRun_SimpleString("import sys");
	PyChess board = PyChess();
	board.printBoard();
	PyChess board2 = board.copy();
	board.push_san("e3");
	board.printBoard();
	cout << "-------------------" << endl;
	
	std::vector<std::string> tmp;
	
	cout<<board.turn()<<endl;

	tmp=board.legal_moves();

	std::vector<std::string>::iterator itr;

	for (itr = tmp.end()-1; itr != tmp.begin(); itr-=1) {
		cout << *itr << endl;
	}
	cout << "-------------------" << endl;
	board2.printBoard();
	board.print_ex();
	cout << "-------------------" << endl;
	

	//board1.PrintBoard();
	//if (Py_IsInitialized()) {
	//	Py_Finalize();
	//}
	return 0;
} 