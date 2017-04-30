#pragma once
#include "Tree.h"

class Monte {
private:
	Tree* tree;
	int expand_visit;
	int select_depth;
	int repeat_num;
	int simulation_num;
	bool turn;
public:
	Monte::Monte(); // board state 입력, turn 초기화
	Monte::Monte(PyChess Board);
	void Monte::destroy();
	char* Monte::predict();
	bool  Monte::selection(int Depth);
	char*  Monte::expantion();
	char*  Monte::simulation();
	char*  Monte::backpropagation(char* Result);
	char*  Monte::choice();
};