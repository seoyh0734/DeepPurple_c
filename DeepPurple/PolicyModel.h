#pragma once

class PolicyModel {
private:


public:
	PolicyModel::PolicyModel();
	virtual PolicyModel::~PolicyModel();
	float* PolicyModel::ask_Scores(char* tmpBoard);


};