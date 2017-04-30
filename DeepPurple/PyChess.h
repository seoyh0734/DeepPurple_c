#pragma once
#include <Python.h>
#include <sstream>
#include <vector>
#include <iostream>
#include "Moveset.h"

using namespace std;


class PyChess {
private:

	PyObject* pModule;
	PyObject* pDict;
	PyObject* pClass;
	PyObject* board;

public:

	PyChess::PyChess();

	PyChess::PyChess(PyObject* Board);

	PyChess::~PyChess();

	void PyChess::printBoard();

	char* PyChess::push_san(char * San);

	Moveset* PyChess::legal_moves();

	void PyChess::print_legal_moves();
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


	void PyChess::destroy();
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