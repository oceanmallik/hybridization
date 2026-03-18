[!NOTE]
> ONLY ARM64 WORKS FOR NOW
To compile the c: 
```bash
gcc -shared -o subtraction.so -fPIC subtraction.c
```

To commpile the C#: 
```bash
dotnet publish CSharpMath/CSharpMath.csproj -c Release -r linux-arm64
cp CSharpMath/bin/Release/net10.0/linux-arm64/publish/multiplication .
```

To compile the c++:
```bash
g++ calculator.cpp subtraction.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)
```

To run the project: 
```bash
./main
```
