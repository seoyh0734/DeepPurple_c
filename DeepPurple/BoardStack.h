#pragma once
#include "Stack.h"

class BoardStack {
private:
	// chessboard 생성해야함 ( Embedding python )
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
