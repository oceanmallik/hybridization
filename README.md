# 5-Language Polyglot Calculator

This project seamlessly links Python, C, C#, and Rust through a master C++ orchestrator. 

> [!NOTE]
> This project currently supports Linux on both **ARM64** (Apple Silicon VMs, Raspberry Pi) and standard **x64** (Intel/AMD) architectures. Run the commands below based on your system.

### 1. Compile the C Library (Subtraction)
*(This command automatically detects your architecture)*
```bash
gcc -shared -o subtraction.so -fPIC subtraction.c
```

### 2. Compile the C# Executable (Multiplication - .NET 10)

**For ARM64 Linux:**
```bash
dotnet publish CSharpMath/CSharpMath.csproj -c Release -r linux-arm64
cp CSharpMath/bin/Release/net10.0/linux-arm64/publish/multiplication .
```

**For x64 Linux (Standard Intel/AMD):**
```bash
dotnet publish CSharpMath/CSharpMath.csproj -c Release -r linux-x64
cp CSharpMath/bin/Release/net10.0/linux-x64/publish/multiplication .
```

### 3. Compile the Rust Library (Division)
*(Cargo automatically detects your architecture)*
```bash
cd division
cargo build --release
cd ..
cp division/target/release/libdivision.so .
```

### 4. Compile the C++ Orchestrator (The Brain)
*(This command automatically detects your architecture and links the Python environment)*
```bash
g++ calculator.cpp subtraction.so libdivision.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)
```

### 5. Run the Project
```bash
./main
```
