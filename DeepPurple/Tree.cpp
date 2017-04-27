#include "Tree.h"

Tree::Tree() {
	root_Node = new Node;
	current_Node = root_Node;
	BoardStack board_stack = BoardStack();
	PolicyModel pm = PolicyModel();
};
Tree::Tree(char* BoardString) {
	root_Node = new Node;
	current_Node = root_Node;
	BoardStack board_stack = BoardStack(BoardString);
	PolicyModel pm = PolicyModel();
};
Tree::~Tree() {
	if (!(current_Node == root_Node))
		delete current_Node;
	
	delete root_Node;
};

void Tree::go_root() {
	current_Node = root_Node;
};

Node* Tree::get_currentNode() {
	return current_Node;
};

void Tree::make_policyNextChildren() {
	;

};

void Tree::make_policyNextRandomChildBoard() {

};

Node* Tree::get_rootNode() {
	return root_Node;
};

char* Tree::get_result() {
	return board_stack.get_Result();
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

bool Tree::get_turn() {
	return board_stack.get_Turn();
};
