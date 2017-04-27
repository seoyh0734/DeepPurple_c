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
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyChess board = PyChess();
	board.printBoard();

	cout << board.turn() << endl;
	board.push_san("e3");
	cout << board.turn() << endl;
	//board1.PrintBoard();
	//if (Py_IsInitialized()) {
	//	Py_Finalize();
	//}
	return 0;
} 