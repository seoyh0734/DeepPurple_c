#include <Python.h>
#include <iostream>


using namespace std;

void printMyDef()
{
	PyObject* mydef = PyImport_ImportModule("scripts.MyChess");
	if (mydef) {
		PyObject* printHello = PyObject_GetAttrString(mydef, "PrintMyDef");
		if (printHello) {
			PyObject *r = PyObject_CallFunction(printHello, NULL);
			if (r == Py_None) {
				printf("None is returned.\n");
				Py_XDECREF(r);
			}
			Py_XDECREF(printHello);
		}
		Py_XDECREF(mydef);
	}
}

PyObject* makeChessBoard()
{
	PyObject* mydef = PyImport_ImportModule("scripts.MyChess");
	if (mydef) {
		PyObject* printHello = PyObject_GetAttrString(mydef, "makeChessBoard");
		if (printHello) {
			PyObject *r = PyObject_CallFunction(printHello, NULL);
			if (r == Py_None) {
				printf("None is returned.\n");
				Py_XDECREF(r);
			}
			else
				//cout << r << endl;
				Py_XDECREF(printHello);
				return r;
		}
		Py_XDECREF(mydef);
	}
}

void push()
{
	PyObject* mydef = PyImport_ImportModule("scripts.MyChess");
	if (mydef) {
		PyObject* push_ = PyObject_GetAttrString(mydef, "push");
		if (push_) {
			PyObject *r = PyObject_CallFunction(push_, NULL);
			if (r == Py_None) {
				printf("None is returned.\n");
				Py_XDECREF(r);
			}
			else
				//cout << r << endl;
				Py_XDECREF(push_);
		}
		Py_XDECREF(mydef);
	}
}

void push2()
{
	PyObject* mydef = PyImport_ImportModule("scripts.MyChess");
	if (mydef) {
		PyObject* push_ = PyObject_GetAttrString(mydef, "push2");
		if (push_) {
			PyObject *r = PyObject_CallFunction(push_, NULL);
			if (r == Py_None) {
				printf("None is returned.\n");
				Py_XDECREF(r);
			}
			else
				//cout << r << endl;
				Py_XDECREF(push_);
		}
		Py_XDECREF(mydef);
	}
}

void test_board()
{
	PyObject* mydef = PyImport_ImportModule("scripts.MyChess");
	if (mydef) {
		PyObject* push_ = PyObject_GetAttrString(mydef, "make");
		if (push_) {
			PyObject *r = PyObject_CallFunction(push_, NULL);
			if (r == Py_None) {
				printf("None is returned.\n");
				Py_XDECREF(r);
			}
			else{
				//cout << r << endl;
				PyObject* view_ = PyObject_GetAttrString(mydef, "view");
				PyObject* r2 = PyObject_CallFunction(view_, "chess.Board",r);
			}
				Py_XDECREF(push_);
		}
		Py_XDECREF(mydef);
	}
}
void chessClass()
{
	PyObject* pModule = PyImport_ImportModule("scripts.MyChess");
	PyObject* pDict = PyModule_GetDict(pModule);
	PyObject* pClass = PyDict_GetItemString(pDict, "MyChess");
	PyObject* pInst = PyObject_CallObject(pClass,NULL);
	PyObject* pValue = PyObject_CallMethod(pInst, "print_board", NULL, NULL);
	PyObject* pValue1 = PyObject_CallMethod(pInst, "push_san", "s", "e3");
	PyObject* pValue2 = PyObject_CallMethod(pInst, "print_board", NULL, NULL);
	PyObject* pValue3 = PyObject_CallMethod(pInst, "legal_moves", NULL, NULL);
	PyObject* pValue4 = PyObject_CallMethod(pInst, "just_print", NULL, NULL);
	cout << pValue3 << endl;
	PyObject_CallMethod(pInst, "pop", NULL, NULL);
	PyObject_CallMethod(pInst, "print_board", NULL, NULL);
}

int main(int argc, char* argv[])
{
	Py_Initialize();
	PyRun_SimpleString("import sys");

	chessClass();
	if (Py_IsInitialized()) {
		Py_Finalize();
	}
	return 0;
} 