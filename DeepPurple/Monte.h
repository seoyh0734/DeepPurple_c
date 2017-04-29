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
	Monte::Monte(PyChess Board);
	string Monte::predict();
	bool  Monte::selection(int Depth);
	string  Monte::expantion();
	char*  Monte::simulation();
	string  Monte::backpropagation(string Result);
	string  Monte::choice();
};