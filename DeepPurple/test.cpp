#include <Python.h>
#include <iostream>


using namespace std;

void printMyDef()
{
	PyObject* mydef ;
	cout << PyImport_ImportModule("scripts.my_def") << endl;
	mydef = PyImport_ImportModule("scriptss.my_def");
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



int main(int argc, char* argv[])
{
	Py_Initialize();
	//wchar_t pStr1[100];
	//MultiByteToWideChar(CP_ACP, 0, (LPSTR)argv[1], -1, pStr1, 100);
	//Py_SetProgramName(pStr1);
	//cout << Py_GetProgramName()<<"\n";
	//PySys_SetArgv();
	PyRun_SimpleString("import sys");
	//PyRun_SimpleString("sys.path.append(argv[0])");
	PyRun_SimpleString("print(sys.path)");
	printMyDef();
	cout << argv[0]<<"\n";

	if (Py_IsInitialized()) {
		//PyRun_SimpleString("print('Hello, World')");
		Py_Finalize();
	}
	return 0;
}