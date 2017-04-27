#include "PolicyModel.h"


PolicyModel::PolicyModel() {

	moves;
	scores = NULL;
	len = NULL;

};
PolicyModel::~PolicyModel() {
	delete scores;
};

void  PolicyModel::calc(PyChess Board) {
	moves = Board.legal_moves();
	//cout << moves.size() << endl;
	len = (int)moves.size();
	scores = new float[len];
	for (int i = 0; i < len; i++) {
		float r = (float)rand() / RAND_MAX;
		scores[i] = r;
	}	
};
float* PolicyModel::ask_Scores() {
	return scores;
};
vector<string> PolicyModel::ask_moves() {
	return  moves;
};

int  PolicyModel::get_len() {
	return len;
};

