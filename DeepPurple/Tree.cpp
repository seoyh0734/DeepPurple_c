#include "Tree.h"

Tree::Tree() {
	root_Node = new Node;
	current_Node = root_Node;
	//board_stack;
	//pm;
};
Tree::~Tree() {
	if (!(current_Node == root_Node))
		delete current_Node;
	
	delete root_Node;
	
};
void Tree::reset_board() {
	
};
void Tree::go_root() {
	current_Node = root_Node;
};
void Tree::set_boardString() {
	
};
Node* Tree::get_currentNode() {
	return current_Node;
};
void Tree::make_policyNextChildren() {
	
};
void Tree::make_policyNextRandomChildBoard() {

};
Node* Tree::get_rootNode() {
	return root_Node;
};
char* Tree::get_result() {
	return "";
};
void Tree::go_next() {
	current_Node = current_Node->get_bestChild();
};
void Tree::go_parrent() {
	current_Node = root_Node;
};
void Tree::get_currentBoard() {
	
};
void Tree::check_board() {
};
