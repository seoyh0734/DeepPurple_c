#pragma once
#include <Python.h>
#include "PyChess.h"

class PyChess {
private:

	PyObject* pModule = PyImport_ImportModule("scripts.MyChess");
	PyObject* pDict = PyModule_GetDict(pModule);
	PyObject* pClass = PyDict_GetItemString(pDict, "MyChess");
	PyObject* board;

public:

	PyChess::PyChess();

	PyChess::PyChess(PyObject* Board);

	void PyChess::printBoard();

	char* PyChess::push_san(char * San);

	char* PyChess::legal_moves();

	void PyChess::pop();

	PyChess PyChess::copy();

	char* PyChess::result();

	bool PyChess::turn();

	bool PyChess::is_game_over();

	bool  PyChess::can_claim_threefold_repetition();
	bool  PyChess::can_claim_fifty_moves();
	bool  PyChess::can_claim_draw();
	bool  PyChess::is_fivefold_repetition();
	bool  PyChess::is_seventyfive_moves();
	bool  PyChess::is_stalemate();
	bool  PyChess::is_insufficient_material();
	bool  PyChess::is_checkmate();

	bool PyChess::is_check_reason();
};


//class ChessPython {
//private:
//	//char* board;
//	bool turn;
//	//char** legal_moves;
//
//public:
//	void ChessPython::board();
//	void ChessPython::board(char* BoardString);
//	void ChessPython::push(char* command);
//	void ChessPython::push_san(char* command_san);
//	char** ChessPython::legal_moves();
//	bool ChessPython::result();
//	bool ChessPython::is_game_over();
//	bool ChessPython::can_claim_threefold_repetition();
//	bool ChessPython::can_claim_fifty_moves();
//	bool ChessPython::can_claim_draw();
//	bool ChessPython::is_fivefold_repetition();
//	bool ChessPython::is_seventyfive_moves();
//
//};