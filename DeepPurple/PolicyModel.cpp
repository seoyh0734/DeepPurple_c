#include "PolicyModel.h"


PolicyModel::PolicyModel() {

	moves;
	scores = NULL;
	len = NULL;

};
PolicyModel::~PolicyModel() {
};

void PolicyModel::destroy() {
	delete scores;
	moves->destroy();
};

void  PolicyModel::calc(PyChess Board) {
	moves = Board.legal_moves();
	len = moves->get_moves_num();
	scores = new float[len];
	for (int i = 0; i < len; i++) {
		float r = (float)rand() / RAND_MAX;
		scores[i] = r;
	}	
};
float* PolicyModel::ask_Scores() {
	return scores;
};
char** PolicyModel::ask_moves() {
	return  moves->get_movearray();
};

int  PolicyModel::get_len() {
	return len;
};



