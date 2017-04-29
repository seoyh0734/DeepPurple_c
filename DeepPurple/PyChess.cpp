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

char* PyChess::push_san(string San) {
	PyObject* pValue = PyObject_CallMethod(board, "push_san", "s", San.c_str());
	if (pValue) {
		Py_XDECREF(pValue);
	}
	char* tmp;
	return "";
};

vector<string> PyChess::legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "legal_moves", NULL, NULL);
	string total = _PyUnicode_AsString(pValue);
	if (pValue) {
		Py_XDECREF(pValue);
	}
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

void PyChess::print_legal_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "print_legal_moves", NULL, NULL);
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
	string result = _PyUnicode_AsString(pValue);
	if (result == "True")
		return true;
	return false;
};

bool PyChess::is_game_over() {
	PyObject* pValue = PyObject_CallMethod(board, "is_game_over", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue) 
		Py_XDECREF(pValue);
	if (result == "True")
		return true;
	return false;
};

bool  PyChess::can_claim_threefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_threefold_repetition", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result == "True")
		return true;
	return false;
};

bool  PyChess::can_claim_fifty_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_fifty_moves", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result == "True")
		return true;
	return false;
};

bool  PyChess::can_claim_draw() {
	PyObject* pValue = PyObject_CallMethod(board, "can_claim_draw", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result == "True")
		return true;
	return false;
};

bool  PyChess::is_fivefold_repetition() {
	PyObject* pValue = PyObject_CallMethod(board, "is_fivefold_repetition", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);
	if (result == "True")
		return true;
	return false;
};

bool  PyChess::is_seventyfive_moves() {
	PyObject* pValue = PyObject_CallMethod(board, "is_seventyfive_moves", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result == "True")
		return true;
	return false;
};

bool  PyChess::is_stalemate(){
	PyObject* pValue = PyObject_CallMethod(board, "is_stalemate", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result == "True")
		return true;
	return false;
};

bool  PyChess::is_insufficient_material() {
	PyObject* pValue = PyObject_CallMethod(board, "is_insufficient_material", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result == "True")
		return true;
	return false;
};

bool  PyChess::is_checkmate() {
	PyObject* pValue = PyObject_CallMethod(board, "is_checkmate", NULL, NULL);
	string result = _PyUnicode_AsString(pValue);
	if (pValue)
		Py_XDECREF(pValue);

	if (result == "True")
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

