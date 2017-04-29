#include <Python.h>
#include "Monte.h"


using namespace std;


int main(int argc, char* argv[])
{
	Py_Initialize();
	if (Py_IsInitialized()) {
		
		PyChess board = PyChess();
		board.printBoard();
		string choice = "";
		//cout << board.result() << endl;
		while (!board.is_game_over()) {
			if (board.turn()) {
				cin >> choice; 
			}
			else {
				Monte monte = Monte(board);
				choice = monte.predict();
			}
			board.push_san(choice);
		}

		//char * choice = monte.predict();
		//cout << choice << endl;
		//string asd;
		board.legal_moves();
		Py_Finalize();
	}
	return 0;
} 

