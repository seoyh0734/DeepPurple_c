#include "Monte.h"

Monte::Monte() {
};
Monte::Monte(PyChess Board) {
	Tree tree = Tree(Board.copy());
	expand_visit = 5;
	select_depth = 20;
	repeat_num = 1;
	simulation_num = 1;
	turn = tree.get_turn();
};

char* Monte::predict() {
	char * last_result;
	for (int i = 0; i < repeat_num; i++) {
		cout << i << "번째 탐색" << endl;
		tree.get_currentBoard().printBoard();
		int depth = 0;

		bool selection_result = selection(depth);

		if (!selection_result) { // 탐색중 게임이 끝나지 않았다면
			bool result = expantion();
			if (result) // 확장 중 게임이 끝났다면
				last_result = tree.get_result();
			else // 확장시에도 게임이 끝나지 않았다면
				last_result = simulation(); // 시뮬레이션을 통해 결과 반환
		}	
		else // 탐색중 게임이 끝났다면
			last_result = tree.get_result();
	}
	backpropagation(last_result);

	char* the_choice = choice();

	return the_choice;
};

bool  Monte::selection(int Depth) {
	cout << "selection" << endl;
	tree.make_policyNextChildren();
	return false;
};

bool  Monte::expantion() {
	cout << "expantion" << endl;
	return true;
};

char*  Monte::simulation() {
	cout << "simulation" << endl;
	return "";
};

int  Monte::backpropagation(char* Result) {
	cout << "backpropagation" << endl;
	return 1;
};

char*  Monte::choice() {
	cout << "choice" << endl;
	return "아직 결과가 없음";
};