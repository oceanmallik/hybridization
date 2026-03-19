#include <iostream>
#include <Python.h>
#include <string>
#include <limits>
#include <cstdlib>

extern "C" int sub();
extern "C" int divide();

int main()
{
	char op;
	std::cout << "[C++] Choose operator (+, -, * or /)";
	std::cin >> op;
	// flushes leftover input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (op)
	{
		case '+':
		{
			Py_Initialize();
			PyRun_SimpleString("import sys; sys.path.append('.')");
			// Runs on the python file like a command (imports stuff)
			PyRun_SimpleString("import addition; addition.add()");
			// Runs addition.py and calls out function add()
			Py_Finalize();
			break;
		}
		case '-':
		{
			sub();
			break;
		}
		case '*':
		{
			system("./multiplication");
			break;
		}
		case '/':
		{
			divide();
			break;
		}
		default:
			std::cout << "Invalid Operator!" << std::endl;
	}
	
	
	
	return 0;
	
}
