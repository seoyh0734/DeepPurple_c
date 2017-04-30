#include "Moveset.h"



Moveset::Moveset() {
};

Moveset::Moveset(char* Sentence) {
	analize(Sentence);
};

Moveset::~Moveset() {
};


void Moveset::destroy() {
	for (int i = 0; i < moves_num; i++) {
		delete movearray[i];
	}
	delete movearray;
	delete this;
};


void Moveset::analize(char* Sentence) {
	moves_num = HowMany(Sentence);
	movearray = get_movearray(moves_num, Sentence);
};

char** Moveset::get_movearray() {
	return movearray;
};
int Moveset::get_moves_num() {
	return moves_num;
};



int Moveset::HowMany(char* Sentence) {
	int num = 0;
	for (int i = 0; Sentence[i] != NULL; i++) {
		if (Sentence[i] == ',') {
			num++;
		}
	}
	return num + 1;
};

char** Moveset::get_movearray(int Len, char* Sentence) {
	char** movearray = new char*[Len];

	for (int i = 0; i < Len; i++)
		movearray[i] = new char[8];

	int n = 0;
	int s = 0;

	for (int i = 0; Sentence[i] != NULL; i++) {
		if (Sentence[i] != ',') {
			if (Sentence[i] != ' ') {
				movearray[n][s] = Sentence[i];
				s++;
			}
			else {
				movearray[n][s] = '\0';
				n++;
				s = 0;
				continue;
			}
		}
		else {
			continue;
		}
	}

	movearray[n][s] = '\0';
	return movearray;
};
