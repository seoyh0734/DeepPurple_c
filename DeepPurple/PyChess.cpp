#include "PyChess.h"



vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

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

char* PyChess::push_san(string San) {
	PyObject* pValue = PyObject_CallMethod(board, "push_san", "s", San.c_str());
	char* tmp;
	return "";
};

vector<string> PyChess::legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "legal_moves", NULL, NULL);
	string total = _PyUnicode_AsString(pValue);
	//cout << total << endl;
	vector<string> strs = split(total, ',');
	vector<string> tmp1 = split(strs[0], '(');
	strs[0] = tmp1[1];
	if (strs.size() != 1) {
		vector<string> tmp2 = split(strs[strs.size() - 1], ')');
		strs[strs.size() - 1] = tmp2[0];
	}
	for (int i = 1; i < strs.size(); i++)
		strs[i] = split(strs[i], ' ')[1];
	if (strs.size() == 1) {
		vector<string> tmp2 = split(strs[strs.size() - 1], ')');
		strs[strs.size() - 1] = tmp2[0];
	}
	//for (int i = 0; i < strs.size(); i++)
	//	cout << strs[i] << endl;

	return strs;
};

PyChess PyChess::copy() {
	PyObject* pValue = PyObject_CallMethod(board, "copy", NULL, NULL);
	PyChess tmpBoard = PyChess(pValue);
	return tmpBoard;
};

void PyChess::pop() {
	PyObject* pValue = PyObject_CallMethod(board, "pop", NULL, NULL);
};

string PyChess::result() {
	PyObject* pValue = PyObject_CallMethod(board, "result", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	return result;
};

bool PyChess::turn() {
	PyObject* pValue = PyObject_CallMethod(board, "turn", NULL, NULL);
	return pValue;
};

bool PyChess::is_game_over() {
	
	PyObject* pValue = PyObject_CallMethod(board, "is_game_over", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (result == "True")
		return true;
	return false;
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

bool PyChess::is_check_reason() {
	return true;
};

