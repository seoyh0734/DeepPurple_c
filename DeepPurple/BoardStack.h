#pragma once
#include "Stack.h"

class BoardStack {
private:
	Stack boardStack;


public:
	BoardStack::BoardStack();
	void BoardStack::push(char* command);
	char* BoardStack::pop();
	void display_Board();
	char* get_ChessBoard();

		
};
