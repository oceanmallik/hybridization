To compile the c: 
```bash
gcc -shared -o subtraction.so -fPIC subtraction.c
```

To compile the c++:
```bash
g++ calculator.cpp subtraction.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)
```

To run the project: 
```bash
./main
```
