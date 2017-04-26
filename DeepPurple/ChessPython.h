#pragma once

class ChessPython {
private:
	//char* board;
	bool turn;
	//char** legal_moves;

public:
	void ChessPython::board();
	void ChessPython::board(char* BoardString);
	void ChessPython::push(char* command);
	void ChessPython::push_san(char* command_san);
	char** ChessPython::legal_moves();
	bool ChessPython::result();
	bool ChessPython::is_game_over();
	bool ChessPython::can_claim_threefold_repetition();
	bool ChessPython::can_claim_fifty_moves();
	bool ChessPython::can_claim_draw();
	bool ChessPython::is_fivefold_repetition();
	bool ChessPython::is_seventyfive_moves();

};