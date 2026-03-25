#include <iostream>
#include <Python.h>
#include <string>
#include <limits>
#include <cstdlib>

#ifdef _WIN32
    #include "python_config.h"
#endif

extern "C" int sub();
extern "C" int divide();

int main()
{
	char op;
	std::cout << "Welcome to Polyglot Calculator" << std::endl;
	std::cout << "[Python >> +] [C >> -] [C# >> *] [Rust >> /]" << std::endl;
	std::cout << "[C++] Choose operator (+, -, * or /)";
	std::cin >> op;
	// flushes leftover input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (op)
	{
		case '+':
		{
            #ifdef _WIN32
                PyConfig config;
                PyConfig_InitPythonConfig(&config);
                PyConfig_SetString(&config, &config.home, PYTHON_HOME_PATH);
                Py_InitializeFromConfig(&config);
                PyConfig_Clear(&config);
            #else
                Py_Initialize();
            #endif
				PyRun_SimpleString("import sys; sys.path.append('.')");
				PyRun_SimpleString("import addition; addition.add()");
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
			// only for linux: system("./multiplication");
            #ifdef _WIN32
                system("multiplication.exe");
            #else
                system("./multiplication");
            #endif
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
