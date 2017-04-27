#include "PyChess.h"

PyChess::PyChess() {
	board = PyObject_CallObject(pClass, NULL);
};

void PyChess::printBoard() {
	PyObject* pValue = PyObject_CallMethod(board, "print_board", NULL, NULL);
};

char* PyChess::push_san(char * San) {
	PyObject* pValue = PyObject_CallMethod(board, "push_san", "s", San);
	char* tmp;
	return "";
};

char* PyChess::legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "legal_moves", NULL, NULL);
	char* tmp;

	return "";
};
PyObject* PyChess::copy() {
	PyObject* pValue = PyObject_CallMethod(board, "copy", NULL, NULL);


	return pValue;
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
	return pValue;
};

bool PyChess::is_game_over() {
	return true;
};

bool  PyChess::can_claim_threefold_repetition() {
	return true;
};
bool  PyChess::can_claim_fifty_moves() {
	return true;
};
bool  PyChess::can_claim_draw() {
	return true;
};
bool  PyChess::is_fivefold_repetition() {
	return true;
};
bool  PyChess::is_seventyfive_moves() {
	return true;
};
bool  PyChess::is_stalemate(){
	return true;
};
bool  PyChess::is_insufficient_material() {
	return true;
};
bool  PyChess::is_checkmate() {
	return true;
};