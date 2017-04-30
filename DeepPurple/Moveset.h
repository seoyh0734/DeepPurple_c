#pragma once

#include <iostream>

class Moveset {
private:
	char** movearray;
	int moves_num;
public:
	Moveset::Moveset();
	Moveset::Moveset(char* Sentence);
	Moveset::~Moveset();

	void Moveset::destroy();

	char** Moveset::get_movearray();
	int Moveset::get_moves_num();

	void Moveset::analize(char* Sentence);
	int Moveset::HowMany(char* Sentence);
	char** Moveset::get_movearray(int Len, char* Sentence);
};