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
		cout << i << "��° Ž��" << endl;
		tree.get_currentBoard().printBoard();
		int depth = 0;

		bool selection_result = selection(depth);

		if (!selection_result) { // Ž���� ������ ������ �ʾҴٸ�
			bool result = expantion();
			if (result) // Ȯ�� �� ������ �����ٸ�
				last_result = tree.get_result();
			else // Ȯ��ÿ��� ������ ������ �ʾҴٸ�
				last_result = simulation(); // �ùķ��̼��� ���� ��� ��ȯ
		}	
		else // Ž���� ������ �����ٸ�
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
	return "���� ����� ����";
};