#include "PyChess.h"
#include <string.h>

PyChess::PyChess() {
	board = PyObject_CallObject(pClass, NULL);
};

PyChess::PyChess(PyObject* Board) {
	board = Board;
};

void PyChess::printBoard() {
	PyObject* pValue = PyObject_CallMethod(board, "print_board", NULL, NULL);
};

char* PyChess::push_san(char * San) {
	PyObject* pValue = PyObject_CallMethod(board, "push_san", "s", San);
	char* tmp;
	return "";
};

std::vector<std::string> PyChess::legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "legal_moves", NULL, NULL);
	int size = PyList_GET_SIZE(pValue);
	int i = 0;
	std::vector<std::string> iVector;
	


	while (i < size) {
		PyObject *tmp = PyList_GetItem(pValue, i++);
		PyObject* pStrObj = PyUnicode_AsUTF8String(tmp);
		char* zStr = PyBytes_AsString(pStrObj);
		char* zStrDup = strdup(zStr);
		iVector.insert(iVector.begin(), zStrDup);
		Py_DECREF(pStrObj);
	}
	return iVector;
};
PyChess PyChess::copy() {
	
	PyObject* pValue = PyObject_CallMethod(board, "copy", NULL, NULL);
	PyChess tmp = PyChess(pValue);
	return tmp;
};

void PyChess::pop() {
	PyObject* pValue = PyObject_CallMethod(board, "pop", NULL, NULL);


};

bool PyChess::result() {
	PyObject* pValue = PyObject_CallMethod(board, "result", NULL, NULL);
	bool tmp = PyBool_Check(pValue);

	return tmp;
};

bool PyChess::turn() {
	PyObject* pValue = PyObject_CallMethod(board, "turn", NULL, NULL);
	
	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}
	
};

bool PyChess::is_game_over() {
	PyObject* pValue = PyObject_CallMethod(board, "is_game_over", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}

};

bool  PyChess::can_claim_threefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_threefold_repetition", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}

};

bool  PyChess::can_claim_fifty_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_fifty_moves", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

bool  PyChess::can_claim_draw() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_draw", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

bool  PyChess::is_fivefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "is_fivefold_repetition", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

bool  PyChess::is_seventyfive_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "is_seventyfive_moves", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

bool  PyChess::is_stalemate(){
	PyObject* pValue = PyObject_CallMethod(board, "is_stalemate", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}

};

bool  PyChess::is_insufficient_material() {
	PyObject* pValue = PyObject_CallMethod(board, "is_insufficient_material", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

bool  PyChess::is_checkmate() {
	PyObject* pValue = PyObject_CallMethod(board, "is_checkmate", NULL, NULL);

	int truthy = PyObject_IsTrue(pValue);

	if (truthy)
	{
		return true;
	}
	else
	{
		return false;
	}


};

void PyChess::print_ex() {
	PyObject* pValue = PyObject_CallMethod(board, "test", NULL,NULL);
};