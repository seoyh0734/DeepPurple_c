#include "Tree.h"
#include <stdlib.h>
#include <Windows.h>


float randomDouble(void) {
	return (float)rand() / RAND_MAX;
}




Tree::Tree() {
	srand(GetTickCount());
	root_Node = new Node;
	current_Node = root_Node;
	board = PyChess();
	pm = PolicyModel();
};

Tree::Tree(PyChess Board) {
	srand(GetTickCount());
	root_Node = new Node;
	current_Node = root_Node;
	board = Board;
	pm = PolicyModel();
};

Tree::~Tree() {

};

void Tree::destroy() {
	root_Node->destroy();
	board.destroy();
};

void Tree::go_root() {
	current_Node = root_Node;
};

Node* Tree::get_currentNode() {
	return current_Node;
};

void Tree::make_policyNextChildren() {

	char Wwin = '0';
	char Bwin = '1';
	char Draw = '2';

	PyChess tmpBoard = board.copy();
	bool turn = tmpBoard.turn();
	pm.calc(tmpBoard);
	tmpBoard.destroy();
	float* policy_points = pm.ask_Scores();
	char** moves = pm.ask_moves();
	int child_len = pm.get_len();
	current_Node->make_Children(child_len);
	for (int i = 0; i < child_len; i++) {
		PyChess tmpBoard2 = board.copy();
		tmpBoard2.push_san(moves[i]);
		if (tmpBoard2.is_game_over()) {
			if (turn) {
				if (tmpBoard2.result()[2] == Wwin) {
					policy_points[i] = 1000000;
				}
				else if (tmpBoard2.result()[2] == Bwin) {
					policy_points[i] = -1000000;
				}
				else if (tmpBoard2.result()[2] == Draw) {
					if (tmpBoard2.is_check_reason())
						policy_points[i] = -1000000;
				}
			}
			else {
				if (tmpBoard2.result()[2] == Wwin) {
					policy_points[i] = -1000000;
				}
				else if (tmpBoard2.result()[2] == Bwin) {
					policy_points[i] = 1000000;
				}
				else if (tmpBoard2.result()[2] == Draw) {
					if (tmpBoard2.is_check_reason())
						policy_points[i] = -1000000;
				}
			}
		}
		tmpBoard2.destroy();
		current_Node->make_Child(i)->setting(current_Node, !turn, moves[i], policy_points[i]);
		
	}

	pm.destroy();
};

PyChess Tree::make_policyNextRandomChildBoard(PyChess Board) {
	//PyChess tmpBoard = Board.copy();
	//bool turn = tmpBoard.turn();

	//// ¿©±â ¹Ù²ã¾ß´ï
	//float policy_points[10];
	//char** moves = new char*[10];
	//int child_len = 10;
	//Node** children = new Node*[child_len];

	//for (int i = 0; i < child_len; i++) {
	//	children[i] = new Node;
	//	PyChess tmpBoard2 = tmpBoard.copy();
	//	//tmpBoard2.push_san(moves[i]);
	//	if (tmpBoard2.is_game_over()) {
	//		if (turn) {
	//			if (tmpBoard2.result() == Wwin) {
	//				policy_points[i] = 1000000;
	//				cout << "¹éÀÌ ÀÌ±â´Â ¼ö" << endl;
	//			}
	//			else if (tmpBoard2.result() == Bwin) {
	//				cout << "¹é : Èæ½Â" << endl;
	//				continue;
	//			}
	//			else if (tmpBoard2.result() == Draw) {
	//				if (tmpBoard2.is_check_reason())
	//					continue;
	//				cout << "¹é ºñ±è" << endl;
	//			}
	//		}
	//		else {
	//			if (tmpBoard2.result() == Wwin) {
	//				cout << "Èæ : ¹é½Â" << endl;
	//				continue;
	//			}
	//			else if (tmpBoard2.result() == Bwin) {
	//				policy_points[i] = 1000000;
	//				cout << "ÈæÀÌ ÀÌ±â´Â ¼ö" << endl;
	//			}
	//			else if (tmpBoard2.result() == Draw) {
	//				if (tmpBoard2.is_check_reason())
	//					continue;
	//				cout << "Èæ ºñ±è" << endl;
	//			}
	//		}
	//	}
	//	children[i]->setting(current_Node, !turn, moves[i], policy_points[i]);
	//}
	//Node tmpNode = Node();
	//tmpNode.set_Children(child_len, children);
	//float* distribution = tmpNode.get_policyDistribution();								
	//float flag = 0;
	//int index = 0;
	//float rand_num = randomDouble();
	//for (int i = 0; i < child_len; i++) {
	//	if (flag <= rand_num && rand_num <= flag + distribution[i])
	//		break;
	//	else {
	//		index++;
	//		flag += i;
	//	}
	//}
	//Node** tmp_children = tmpNode.get_Children();
	//char* childcommand = tmp_children[index]->get_command();
	//tmpBoard.push_san(childcommand);

	return Board;

};

Node* Tree::get_rootNode() {
	return root_Node;
};

char* Tree::get_result() {
	return board.result();
};

void Tree::go_next() {
	current_Node = current_Node->get_bestChild();
	current_Node->visited();
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

char* Tree::best_choice() {
	return get_rootNode()->For_root_choice();

};
