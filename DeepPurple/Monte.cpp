#include "Monte.h"

Monte::Monte() {
	tree = new Tree;
	expand_visit = 5;
	select_depth = 10;
	repeat_num = 10;
	simulation_num = 1;
	turn = tree->get_turn();
};
Monte::Monte(PyChess Board) {

	tree =new Tree(Board.copy());
	expand_visit = 50000;
	select_depth = 2000;
	repeat_num = 50;
	simulation_num = 10;
	turn = tree->get_turn();
};

void Monte::destroy() {
	tree->destroy();
	delete tree;
};

char* Monte::predict() {
	char* last_result = "";
	for (int i = 0; i < repeat_num; i++) {
		cout << i << "번째 탐색" << endl;
		//tree->get_currentBoard().printBoard();
		int depth = 0;
		bool selection_result = selection(depth);
		if (!selection_result) { // 탐색중 게임이 끝나지 않았다면
			char* result = expantion();
			if (result != "False") // 확장 중 게임이 끝났다면
				last_result = tree->get_result();
			else // 확장시에도 게임이 끝나지 않았다면
				last_result = simulation(); // 시뮬레이션을 통해 결과 반환
		}
		else {	// 탐색중 게임이 끝났다면
			last_result = tree->get_result();
		}
		backpropagation(last_result);
	}

	char* the_choice = choice();

	return  the_choice;
};

bool  Monte::selection(int Depth) {
	if (tree->get_is_GameOver()) {  // 게임이 끝났으면
		cout << Depth << endl;
		cout << tree->get_currentNode()->get_command() << endl;
		cout << tree->get_currentNode()->get_Parent()->get_Color() << endl;
		cout << tree->get_currentBoard().result() << endl;
		//tree->get_currentBoard().printBoard();

		return true;
	}
	else { // 게임이 끝나지 않았다면
		if ( select_depth> Depth) { // 기준 깊이
			//cout << Depth << endl;
			if (!tree->get_currentNode()->get_Flag()) {
				tree->make_policyNextChildren();
				tree->get_currentNode()->on_Flag();
			}	
			tree->go_next();
			return selection(Depth + 1);
		}
		else {
			if (tree->get_currentNode()->get_Flag()) {
				tree->go_next();
				return selection(Depth + 1);
			}
			else {
				tree->get_currentBoard().printBoard();
				tree->get_currentBoard().print_legal_moves();
				return false; //  true;
			}

		}
	}
};

char*  Monte::expantion() {
	if (tree->get_currentNode()->should_expand(expand_visit)) {
		tree->make_policyNextChildren();
		tree->go_next();
		if (tree->get_currentBoard().is_game_over())
			return tree->get_currentBoard().result();
		else {
			return expantion();
		}
	}
	else {
		return "False";
	}
};

char*  Monte::simulation() {
	//cout << "simulation" << endl;
	return "";
};

char*  Monte::backpropagation(char* Result) {
	//cout << Result << endl;
	if (tree->get_currentNode()->is_root()) {
		return "end";
	}
	else {
		tree->get_currentNode()->renew_result(Result);
		tree->go_parrent();
		return backpropagation(Result);
	}
};

char*  Monte::choice() {
	tree->get_rootNode()->print_childInfo();
	char* cho = tree->best_choice();
	//cout << cho << endl;
	return cho;
};