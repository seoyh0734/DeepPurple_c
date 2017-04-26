#include "Monte.h"

Monte::Monte() {
};
Monte::Monte(char* BoardString) {
	Tree tree = Tree(BoardString);
	expand_visit = 5;
	select_depth = 20;
	repeat_num = 10;
	simulation_num = 1;
	turn = tree.get_turn();
};
char* Monte::predict() {

	return "";
};
bool  Monte::selection(int Depth) {
	return true;
};
bool  Monte::expantion() {
	return true;
};
char*  Monte::simualation() {
	return "";
};
int  Monte::backpropagation(int Result) {
	return 1;
};
char*  Monte::choice() {
	return "";
};