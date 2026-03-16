#include <iostream>
#include <Python.h>
#include <string>

int main()
{
	Py_Initialize();
	
	PyRun_SimpleString("import sys; sys.path.append('.')");
	
	PyRun_SimpleString("import addition; addition.add()");
	
	Py_Finalize();
	
	return 0;
	
}
