> [!NOTE]
> ONLY ARM64 WORKS FOR NOW

To compile the c: 
```bash
gcc -shared -o subtraction.so -fPIC subtraction.c
```

To commpile the C# (dotnet 10): 
```bash
dotnet publish CSharpMath/CSharpMath.csproj -c Release -r linux-arm64
cp CSharpMath/bin/Release/net10.0/linux-arm64/publish/multiplication .
```

To compile the rust:
```bash
cd division
cargo build --release
cd ..
cp division/target/release/libdivision.so .
```

To compile the c++:
```bash
g++ calculator.cpp subtraction.so libdivision.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)
```

To run the project: 
```bash
./main
```
