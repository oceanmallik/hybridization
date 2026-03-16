To compile the c: 
```bash
gcc -shared -o subtraction.so -fPIC subtraction.c
```

To compile the c++:
```bash
g++ calculator.cpp -o main $(python3-config --cflags --embed --libs)
```

To run the project: 
```bash
./main
```