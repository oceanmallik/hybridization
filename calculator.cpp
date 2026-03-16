#include <iostream>
#include <Python.h>
#include <string>

int main()
{
	int num1, num2;
	
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2;
	
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");
    
	std::string command = "import addition\n"
						  "result = addition.addition(" + std::to_string(num1) + "," + std::to_string(num2) + ")\n"
						  "print(f'[C++ Side] The total is: {result}')";
	
	PyRun_SimpleString(command.c_str());
	Py_Finalize();
	
	return 0;
	
}
