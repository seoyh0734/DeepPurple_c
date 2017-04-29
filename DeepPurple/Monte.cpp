#include "Monte.h"

Monte::Monte() {
	Tree tree = Tree();
	expand_visit = 5;
	select_depth = 10;
	repeat_num = 10;
	simulation_num = 1;
	turn = tree.get_turn();
};
Monte::Monte(PyChess Board) {
	Tree tree = Tree(Board.copy());
	expand_visit = 50000;
	select_depth = 1000;
	repeat_num = 10;
	simulation_num = 1;
	turn = tree.get_turn();
};

string Monte::predict() {
	string last_result;
	for (int i = 0; i < repeat_num; i++) {
		cout << i << "��° Ž��" << endl;
		//tree.get_currentBoard().printBoard();
		int depth = 0;
		//cout << "1" << endl;
		bool selection_result = selection(depth);
		//cout << "10" << endl;
		//cout << selection_result << endl;
		if (!selection_result) { // Ž���� ������ ������ �ʾҴٸ�
			//cout << "a" << endl;
			string result = expantion();
			if (result != "False") // Ȯ�� �� ������ �����ٸ�
				last_result = tree.get_result();
			else // Ȯ��ÿ��� ������ ������ �ʾҴٸ�
				last_result = simulation(); // �ùķ��̼��� ���� ��� ��ȯ
		}
		else {	// Ž���� ������ �����ٸ�
			//cout << "b" << endl;
			last_result = tree.get_result();
		}
		//cout << "c" << endl;
		//cout << "result: "<<last_result << endl;
		backpropagation(last_result);
	}


	string the_choice = choice();

	return the_choice;
};

bool  Monte::selection(int Depth) {
	//cout << "selection" << endl;
	cout << Depth << endl;
	//tree.get_currentBoard().printBoard();
	//cout << tree.get_turn() << endl;
	//cout << "-----------------" << endl;
	//tree.make_policyNextChildren();
	//tree.get_is_GameOver();
	//cout << tree.get_result() <<endl;
	//cout << "-----------------" << endl;
	if (tree.get_is_GameOver()) {  // ������ ��������
		//cout << "1" << endl;
		return false;
	}
	else { // ������ ������ �ʾҴٸ�
		//cout << "2" << endl;
		if ( select_depth> Depth) { // ���� ����
			//cout << "4" << endl;
			if (!tree.get_currentNode()->get_Flag()) {
				tree.make_policyNextChildren();
				tree.get_currentNode()->on_Flag();
				cout << "�ڽ� ����" << endl;
			}	
			tree.go_next();
			//cout << "5" << endl;
			return selection(Depth + 1);
		}
		else {
			//cout << "6" << endl;
			if (tree.get_currentNode()->get_Flag()) {
				//cout << "7" << endl;
				tree.go_next();
				//cout << "8" << endl;
				return selection(Depth + 1);
			}
			else {
				//cout << "r" << endl;
				cout << tree.get_is_GameOver() << endl;
				tree.get_currentBoard().printBoard();
				tree.get_currentBoard().print_legal_moves();
				return false; //  true;
			}

		}
	}
};

string  Monte::expantion() {
	if (tree.get_currentNode()->should_expand(expand_visit)) {
		//cout << "expantion" << endl;
		tree.make_policyNextChildren();
		tree.go_next();
		if (tree.get_currentBoard().is_game_over())
			return tree.get_currentBoard().result();
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

string  Monte::backpropagation(string Result) {
	cout << "backpropagation" << endl;
	//tree.get_currentBoard().printBoard();
	if (tree.get_currentNode()->is_root()) {
		cout << "root" << endl;
		return "end";
	}
	else {
		tree.get_currentNode()->renew_result(Result);
		tree.go_parrent();
		return backpropagation(Result);
	}
};

string  Monte::choice() {
	//cout << "choice" << endl;
	string cho = tree.best_choice();
	//cout << cho << endl;
	return cho;
};