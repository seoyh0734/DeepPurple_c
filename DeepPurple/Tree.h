#pragma once

#include "Node.h"
#include "BoardStack.h"
#include "PolicyModel.h"
#include "PyChess.h"

class Tree {
private:
	Node* root_Node;
	Node* current_Node;
	PyChess board;
	PolicyModel pm;
public :
	Tree::Tree();
	Tree::Tree(PyChess Board);
	virtual Tree::~Tree();
	void Tree::go_root();
	Node* Tree::get_currentNode();
	void Tree::make_policyNextChildren();
	PyChess Tree::make_policyNextRandomChildBoard(PyChess Board);
	Node* Tree::get_rootNode();
	char* Tree::get_result();
	void Tree::go_next();
	void Tree::go_parrent();
	PyChess Tree::get_currentBoard();
	bool Tree::check_board();
	bool Tree::get_turn();
};