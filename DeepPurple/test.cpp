#include <Python.h>
#include "Monte.h"


using namespace std;


int main(int argc, char* argv[])
{
	Py_Initialize();
	if (Py_IsInitialized()) {
		
		PyChess board = PyChess();
		board.printBoard();

		cout << board.result() << endl;
		Monte monte = Monte(board);
		monte.predict();
		//char * choice = monte.predict();
		//cout << choice << endl;
		//string asd;
		board.legal_moves();
		Py_Finalize();
	}
	return 0;
} 

