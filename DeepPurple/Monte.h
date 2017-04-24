#pragma once

#include "Tree.h"

class Monte {
private:
	Tree tree;
	int expand_visit;
	int select_depth;
	int repeat_num;
	int simulation_num;
	bool turn;
public:
	Monte::Monte(); // board state 입력, turn 초기화
	char* Monte::predict();
	bool  Monte::selection(int Depth);
	bool  Monte::expantion();
	char*  Monte::simualation();
	int  Monte::backpropagation(int Result);
	char*  Monte::choice();

};