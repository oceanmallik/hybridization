#!/bin/bash
set -e 

echo "🔍 Detecting system architecture..."
ARCH=$(uname -m)
if [ "$ARCH" = "aarch64" ]; then
    DOTNET_ARCH="linux-arm64"
elif [ "$ARCH" = "x86_64" ]; then
    DOTNET_ARCH="linux-x64"
else
    echo "❌ Unsupported architecture: $ARCH"
    exit 1
fi
echo "✅ Architecture detected: $DOTNET_ARCH"

echo "⚙️ 1/4 Compiling C Library (Subtraction)..."
gcc -shared -o subtraction.so -fPIC subtraction.c

echo "⚙️ 2/4 Compiling C# Executable (Multiplication)..."
dotnet publish CSharpMath/CSharpMath.csproj -c Release -r $DOTNET_ARCH
cp CSharpMath/bin/Release/net10.0/$DOTNET_ARCH/publish/multiplication .

echo "⚙️ 3/4 Compiling Rust Library (Division)..."
cd division
cargo build --release
cd ..
cp division/target/release/libdivision.so .

echo "⚙️ 4/4 Compiling C++ Orchestrator (The Brain)..."
g++ calculator.cpp subtraction.so libdivision.so -o main -Wl,-rpath,. $(python3-config --cflags --embed --libs)

echo "✅ Build complete! You can now run the calculator using: ./main"