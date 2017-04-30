#pragma once

#include "PyChess.h"


class PolicyModel {
private:
	Moveset* moves;
	float* scores;
	int len;

public:
	PolicyModel::PolicyModel();
	virtual PolicyModel::~PolicyModel();

	void PolicyModel::destroy();
	void  PolicyModel::calc(PyChess Board);
	float* PolicyModel::ask_Scores();
	char** PolicyModel::ask_moves();
	int  PolicyModel::get_len();
};