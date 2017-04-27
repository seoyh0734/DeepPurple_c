#pragma once
#include "Stack.h"

// 필요없는 듯 
class BoardStack {
private:
	Stack moveStack;
	// chessboard 생성해야함 ( Embedding python )
public:
	BoardStack::BoardStack();
	BoardStack::BoardStack(char* BoardString);
	void BoardStack::push(char* command);
	char* BoardStack::pop();
	void BoardStack::display_Board();
	char* BoardStack::get_ChessBoard();
	bool BoardStack::get_GameOver();
	char* BoardStack::get_Result();
	bool BoardStack::get_Color();
	bool BoardStack::get_Turn();
};