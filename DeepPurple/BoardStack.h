#pragma once
#include "Stack.h"

class BoardStack {
private:
	// chessboard �����ؾ��� ( Embedding python )
public:
	BoardStack::BoardStack();
	void BoardStack::push(char* command);
	char* BoardStack::pop();
	void display_Board();
	char* get_ChessBoard();
	bool get_GameOver();
	char* get_Result();
	bool get_Color();
};
