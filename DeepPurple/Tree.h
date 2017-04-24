#pragma once

#include "Node.h"
#include "BoardStack.h"

class Tree {
private:
	Node* root_Node;
	Node* current_Node;
	// board_stack ; 보드 스택
	// pm ; 모델
public :
	Tree::Tree();
	virtual Tree::~Tree();
	void Tree::reset_board();
	void Tree::go_root();
	void Tree::set_boardString();
	Node* Tree::get_currentNode();
	void Tree::make_policyNextChildren();
	void Tree::make_policyNextRandomChildBoard();
	Node* Tree::get_rootNode();
	char* Tree::get_result();
	void Tree::go_next();
	void Tree::go_parrent();
	void Tree::get_currentBoard();
	void Tree::check_board();


};