#include "Tree.h"
#include <stdlib.h>
#include <Windows.h>


float randomDouble(void) {
	return (float)rand() / RAND_MAX;
}


char* Wwin = "1-0";
char* Bwin = "0-1";
char* Draw = "1/2-1/2";

Tree::Tree() {
	srand(GetTickCount());
	root_Node = new Node;
	current_Node = root_Node;
	PyChess board = PyChess();
	PolicyModel pm = PolicyModel();
};

Tree::Tree(PyChess Board) {
	root_Node = new Node;
	current_Node = root_Node;
	PyChess board = Board;
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
	PyChess tmpBoard = board.copy();
	//tmpBoard.printBoard();
	bool turn = tmpBoard.turn();
	pm.calc(tmpBoard);
	// ¿©±â ¹Ù²ã¾ß´ï
	float* policy_points = pm.ask_Scores();
	vector<string> moves = pm.ask_moves();
	int child_len = pm.get_len();
	Node** children = new Node*[child_len];
	for (int i = 0; i < child_len; i++) {
		PyChess tmpBoard2 = tmpBoard.copy();
		children[i] = new Node;
		//cout << moves[i] << endl;
		tmpBoard2.push_san(moves[i]);
		if (tmpBoard2.is_game_over()) {
			if (turn) {
				if (tmpBoard2.result() == Wwin) {
					policy_points[i] = 1000000;
					cout << "¹éÀÌ ÀÌ±â´Â ¼ö" << endl;
				}
				else if (tmpBoard2.result() == Bwin) {
					cout << "¹é : Èæ½Â" << endl;
					policy_points[i] = -1000000;
				}
				else if (tmpBoard2.result() == Draw) {
					if (tmpBoard2.is_check_reason())
						policy_points[i] = -1000000;
					cout << "¹é ºñ±è" << endl;
				}
			}
			else {
				if (tmpBoard2.result() == Wwin) {
					cout << "Èæ : ¹é½Â" << endl;
					policy_points[i] = -1000000;
				}
				else if (tmpBoard2.result() == Bwin) {
					policy_points[i] = 1000000;
					cout << "ÈæÀÌ ÀÌ±â´Â ¼ö" << endl;
				}
				else if (tmpBoard2.result() == Draw) {
					if (tmpBoard2.is_check_reason())
						policy_points[i] = -1000000;
					cout << "Èæ ºñ±è" << endl;
				}
			}
		}
		children[i]->setting(current_Node, !turn, moves[i], policy_points[i]);
	}
	current_Node->set_Children(child_len, children);
};

PyChess Tree::make_policyNextRandomChildBoard(PyChess Board) {
	PyChess tmpBoard = Board.copy();
	bool turn = tmpBoard.turn();

	// ¿©±â ¹Ù²ã¾ß´ï
	float policy_points[10];
	char** moves = new char*[10];
	int child_len = 10;
	Node** children = new Node*[child_len];

	for (int i = 0; i < child_len; i++) {
		children[i] = new Node;
		PyChess tmpBoard2 = tmpBoard.copy();
		//tmpBoard2.push_san(moves[i]);
		if (tmpBoard2.is_game_over()) {
			if (turn) {
				if (tmpBoard2.result() == Wwin) {
					policy_points[i] = 1000000;
					cout << "¹éÀÌ ÀÌ±â´Â ¼ö" << endl;
				}
				else if (tmpBoard2.result() == Bwin) {
					cout << "¹é : Èæ½Â" << endl;
					continue;
				}
				else if (tmpBoard2.result() == Draw) {
					if (tmpBoard2.is_check_reason())
						continue;
					cout << "¹é ºñ±è" << endl;
				}
			}
			else {
				if (tmpBoard2.result() == Wwin) {
					cout << "Èæ : ¹é½Â" << endl;
					continue;
				}
				else if (tmpBoard2.result() == Bwin) {
					policy_points[i] = 1000000;
					cout << "ÈæÀÌ ÀÌ±â´Â ¼ö" << endl;
				}
				else if (tmpBoard2.result() == Draw) {
					if (tmpBoard2.is_check_reason())
						continue;
					cout << "Èæ ºñ±è" << endl;
				}
			}
		}
		children[i]->setting(current_Node, !turn, moves[i], policy_points[i]);
	}
	Node tmpNode = Node();
	tmpNode.set_Children(child_len, children);
	float* distribution = tmpNode.get_policyDistribution();								
	float flag = 0;
	int index = 0;
	float rand_num = randomDouble();
	for (int i = 0; i < child_len; i++) {
		if (flag <= rand_num && rand_num <= flag + distribution[i])
			break;
		else {
			index++;
			flag += i;
		}
	}
	Node** tmp_children = tmpNode.get_Children();
	string childcommand = tmp_children[index]->get_command();
	tmpBoard.push_san(childcommand);

	return tmpBoard;

};

Node* Tree::get_rootNode() {
	return root_Node;
};

string Tree::get_result() {
	return board.result();
};

void Tree::go_next() {
	//cout << current_Node <<endl;
	current_Node = current_Node->get_bestChild();
	//cout << current_Node->get_command() << endl;
	current_Node->visited();
	//cout << current_Node->get_Visit() << endl;
	//cout << current_Node << endl;
	board.push_san(current_Node->get_command());
};

void Tree::go_parrent() {
	current_Node = current_Node->get_Parent();
	board.pop();
};

PyChess Tree::get_currentBoard() {
	return board;
};

bool Tree::check_board() {
	return true;
};

bool Tree::get_turn() {
	return board.turn();
};
bool Tree::get_is_GameOver() {
	return board.is_game_over();
};

string Tree::best_choice() {
	return get_rootNode()->For_root_choice();

};