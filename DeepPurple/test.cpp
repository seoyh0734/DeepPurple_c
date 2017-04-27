#include <Python.h>
#include "Monte.h"

using namespace std;


int main(int argc, char* argv[])
{
	Py_Initialize();
	if (Py_IsInitialized()) {
		
		PyChess board = PyChess();
		Monte monte = Monte(board);
		char * choice = monte.predict();

		cout << choice << endl;
		Py_Finalize();
	}
	return 0;
} 

