# Running C++ in Ubuntu

## 1. Install the C++ Compiler (g++)
If you do not have `g++` (the C++ compiler) installed, you can install it using the following commands:
```bash
sudo apt update
sudo apt install g++
```

## 2. Compile the C++ Code
Open your terminal and navigate to the directory containing your `.cpp` file. Compile the code using:
```bash
g++ filename.cpp -o filename
```
*(Replace `filename.cpp` with your actual file name)*

*Note: The `-o filename` part tells the compiler to name the output file `filename`. If you skip it and just run `g++ filename.cpp`, the default output file will be named `a.out`.*

## 3. Run the Executable
After successfully compiling, run the compiled program with:
```bash
./filename
```
*(If you didn't use the `-o` flag, you would run it using `./a.out` instead).*
