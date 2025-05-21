# Lab 0: Simple Calculator

This project is a simple command-line calculator program written in C++. It allows users to perform basic arithmetic operations: addition, subtraction, multiplication, and division. The program is structured using functions for each operation, as per the assignment requirements.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Task Description

Create a C++ calculator program that prompts the user to select an operation (addition, subtraction, multiplication, division) using functions. The program should include the following functions:

1.  A function to add two numbers.
2.  A function to subtract one number from another.
3.  A function to multiply two numbers.
4.  A function to divide one number by another.

The program should prompt the user for two numbers and the desired operation. Then, it should call the appropriate function and display the result on the screen.

## Features

-   Addition of two numbers.
-   Subtraction of two numbers.
-   Multiplication of two numbers.
-   Division of two numbers (Note: Ensure you handle division by zero if implemented, or be aware of potential runtime errors).
-   User-friendly menu for operation selection.
-   Input of two numbers from the user.
-   Output of the calculated result.

## Technologies Used

-   **Programming Language:** C++
-   **Compiler:** Any standard C++ compiler (e.g., G++, Clang, MSVC)

## How to Compile and Run

1.  **Clone the main repository (if you haven't already):**
    ```bash
    git clone https://github.com/andreypotekhin16/2semester_1cours_c-.git
    ```

2.  **Navigate to this lab's directory:**
    ```bash
    cd 2semester_1cours_c-/Lab_0_culc
    ```

3.  **Compile the C++ source file.**

    Using G++ (common on Linux/macOS):
    ```bash
    g++ Lab_0_Potekhin.cpp -o calculator
    ```
    If using an IDE like Visual Studio or Code::Blocks, you can open `Lab_0_Potekhin.cpp` as part of a project and use the IDE's build/compile functionality.

4.  **Run the compiled executable:**

    On Linux/macOS:
    ```bash
    ./calculator
    ```
    On Windows (if compiled with MinGW/G++ or similar):
    ```bash
    calculator.exe
    ```
    Or simply `calculator` in the Command Prompt if the directory is in PATH or you are in the directory.

    The program will then prompt you to enter two numbers and choose an operation.

## File Structure (within `Lab_0_culc`)

-   `Lab_0_Potekhin.cpp`: Contains the C++ source code for the calculator.
-   `README.md`: This file.

## Author

Andrey Potekhin

## License

This project is part of a larger repository for educational purposes and does not have a specific license for this individual lab beyond the main repository's intent.
