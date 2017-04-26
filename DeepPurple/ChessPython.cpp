#include "ChessPython.h"

void ChessPython::board() {};
void ChessPython::board(char* BoardString) {};
void ChessPython::push(char* command) {};
void ChessPython::push_san(char* command_san) {};
char** ChessPython::legal_moves() {
	char ** tmp;

	return tmp;
};
bool ChessPython::result() {
	return true;
};
bool ChessPython::is_game_over() {
	return true;
};
bool ChessPython::can_claim_threefold_repetition() {
	return true;
};
bool ChessPython::can_claim_fifty_moves(){
	return true;
};
bool ChessPython::can_claim_draw() {
	return true;
};
bool ChessPython::is_fivefold_repetition() {
	return true;
};
bool ChessPython::is_seventyfive_moves() {
	return true;
};
