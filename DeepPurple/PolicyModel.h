#pragma once

#include "PyChess.h"


class PolicyModel {
private:
	vector<string> moves;
	float* scores;
	int len;

public:
	PolicyModel::PolicyModel();
	virtual PolicyModel::~PolicyModel();
	void  PolicyModel::calc(PyChess Board);
	float* PolicyModel::ask_Scores();
	vector<string> PolicyModel::ask_moves();
	int  PolicyModel::get_len();
};