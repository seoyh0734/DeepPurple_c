#include <Python.h>
#include <iostream>
#include "PyChess.h"

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
	
	
	
	cout<<board.turn()<<endl;



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