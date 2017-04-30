#include "PyChess.h"


PyChess::PyChess() {
	pModule = PyImport_ImportModule("scripts.MyChess");
	pDict = PyModule_GetDict(pModule);
	pClass = PyDict_GetItemString(pDict, "MyChess");
	Py_XDECREF(pModule);
	Py_XDECREF(pDict);
	Py_XDECREF(pClass);
	board = PyObject_CallObject(pClass, NULL);

};

PyChess::PyChess(PyObject* Board) {
	board = Board;
};

PyChess::~PyChess() {

};

void PyChess::destroy() {
	Py_XDECREF(board);
};

void PyChess::printBoard() {
	PyObject* pValue = PyObject_CallMethod(board, "print_board", NULL, NULL);
	if (pValue) {
		Py_XDECREF(pValue);
	}

};

char* PyChess::push_san(char * San) {
	PyObject* pValue = PyObject_CallMethod(board, "push_san", "s", San);
	if (pValue) {
		Py_XDECREF(pValue);
	}
	char* tmp;
	return "";
};


Moveset* PyChess::legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "legal_moves", NULL, NULL);
	char* total = _PyUnicode_AsString(pValue);
	if (pValue) {
		Py_XDECREF(pValue);
	}
	Moveset* moveset = new Moveset(total);
	return moveset;
};

void PyChess::print_legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "print_legal_moves", NULL, NULL);
	if (pValue)
		Py_XDECREF(pValue);
};

PyChess PyChess::copy() {
	PyObject* pValue = PyObject_CallMethod(board, "copy", NULL, NULL);
	PyChess tmpBoard = PyChess(pValue);
	return tmpBoard;
};

void PyChess::pop() {
	PyObject* pValue = PyObject_CallMethod(board, "pop", NULL, NULL);
	if (pValue)
		Py_XDECREF(pValue);
};

char* PyChess::result() {
	PyObject* pValue = PyObject_CallMethod(board, "result", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);

	if (pValue)
		Py_XDECREF(pValue);
	//cout << "asd"<< result << endl;
	return result;
};

bool PyChess::turn() {
	PyObject* pValue = PyObject_CallMethod(board, "turn", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result[0] == 'T')
		return true;
	return false;
};

bool PyChess::is_game_over() {
	PyObject* pValue = PyObject_CallMethod(board, "is_game_over", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue) 
		Py_XDECREF(pValue);
	if (result[0] == 'T') 
		return true;
	else
		return false;
};

bool  PyChess::can_claim_threefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_threefold_repetition", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::can_claim_fifty_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_fifty_moves", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::can_claim_draw() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_draw", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::is_fivefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "is_fivefold_repetition", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::is_seventyfive_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "is_seventyfive_moves", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::is_stalemate(){
	PyObject* pValue = PyObject_CallMethod(board, "is_stalemate", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::is_insufficient_material() {
	PyObject* pValue = PyObject_CallMethod(board, "is_insufficient_material", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result[0] == 'T')
		return true;
	return false;
};

bool  PyChess::is_checkmate() {
	PyObject* pValue = PyObject_CallMethod(board, "is_checkmate", NULL, NULL);
	char* result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result[0] == 'T')
		return true;
	return false;
};

bool PyChess::is_check_reason() {
	//cout << "here" << endl;
	bool flag = false;
	if (can_claim_threefold_repetition())
		flag = true;
	//cout << "here1" << endl;
	if (can_claim_fifty_moves())
		flag = true;
	//cout << "here2" << endl;
	if (can_claim_draw())
		flag = true;
	//cout << "here3" << endl;
	if (is_fivefold_repetition())
		flag = true;
	//cout << "here4" << endl;
	if (is_seventyfive_moves())
		flag = true;
	//cout << "here5" << endl;
	return flag;
};

