# 5-Language Polyglot Calculator

This project seamlessly links Python, C, C#, and Rust through a master C++ orchestrator. 

## 📦 Prerequisites

Before building the project, ensure you have the required compilers and SDKs installed for all 5 languages. 

**For Ubuntu/Debian Linux**, you can install the requirements using the commands below:

*   **C / C++:** The standard GNU compilers.
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
*   **Python:** The Python 3 runtime and the C-API development headers (required for `Python.h`).
    ```bash
    sudo apt install python3 python3-dev
    ```
*   **Rust:** The Rust compiler and Cargo package manager. (It is recommended to use `rustup`).
    ```bash
    curl --proto '=https' --tlsv1.2 -sSf [https://sh.rustup.rs](https://sh.rustup.rs) | sh
    ```
*   **C# (.NET 10):** The .NET 10 SDK (required for Native AOT compilation). 
    *Please follow the [Official Microsoft Documentation](https://learn.microsoft.com/en-us/dotnet/core/install/linux) to install the .NET 10 SDK for your specific Linux distribution.*

> [!NOTE]
> This project currently supports Linux on both **ARM64** (Apple Silicon VMs, Raspberry Pi) and standard **x64** (Intel/AMD) architectures. Run the commands below based on your system.

# 🚀 Quick Start (Automated Build)

The easiest way to compile the entire project is to use the included build script. It will automatically detect your system architecture and compile all 5 languages.

### 1. Make the script executable and Run the build script (only needed once)
```bash
chmod +x build.sh
./build.sh
```

### 2. Run the Polyglot Calculator
```bash
./main
```

---

# 🛠️ Manual Compilation Steps

If you prefer to compile each language manually, follow these steps based on your a

### 1. Compile the C Library (Subtraction)
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
```bash
cd division
cargo build --release
cd ..
cp division/target/release/libdivision.so .
```

### 4. Compile the C++ Orchestrator (The Brain)
```bash
g++ calculator.cpp subtraction.so libdivision.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)
```

### 5. Run the Project
```bash
./main
```