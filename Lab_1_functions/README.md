# Lab 1: C++ Functions - Implementations and Applications

This project contains solutions to several programming exercises focused on the implementation and use of functions in C++. Each task tackles a different problem, demonstrating various aspects of function design, parameter passing, return values, and recursion.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Task Descriptions

This lab includes the implementation of functions for the following tasks:

1.  **Task 1: Factorial Calculation**
    *   Write a function to calculate the factorial of a given non-negative integer.
    *   Example: `factorial(5)` should return `120` (5! = 5 * 4 * 3 * 2 * 1).

2.  **Task 2: Array Minimum and Maximum**
    *   Write a function (or functions) to find the minimum and maximum values within an array of numbers.
    *   The function should take an array and its size as input.

3.  **Task 3: Recursive Triangle Drawing**
    *   Write a recursive function to "draw" (print to the console) a triangle of a given height `n` using characters (e.g., asterisks).
    *   Example for height 3:
        ```
        *
        **
        ***
        ```
        (Or the reverse, depending on the specific implementation style required).

4.  **Task 4: Character Occurrence Count in a String**
    *   Write a function to count the number of occurrences of a specific character `c` within a given string `s`.
    *   Example: `countChar("hello world", 'l')` should return `3`.

## Key Concepts Implemented/Learned

-   **User-Defined Functions:** Defining, declaring (prototyping), and calling custom functions.
-   **Parameters and Arguments:** Passing data to functions (e.g., by value, by reference/pointer for arrays).
-   **Return Values:** Functions returning computed results (factorial, min/max, count).
-   **Iteration:** Using loops (e.g., `for`, `while`) for tasks like factorial calculation, array traversal, and string iteration.
-   **Recursion:** Implementing the triangle drawing task using a recursive approach.
-   **Array Manipulation:** Accessing and processing elements of an array (for min/max).
-   **String Manipulation:** Iterating through characters of a string (for character count). C-style strings or `std::string` might be used.
-   **Basic Input/Output:** (Likely in `main` function) for testing the implemented functions.
-   **Modular Programming:** Breaking down problems into smaller, manageable, and reusable functions.

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
    cd 2semester_1cours_c-/Lab_1_functions
    ```

3.  **Compile the C++ source file.**
    Replace `lab1_program` with your desired output executable name.

    Using G++ (common on Linux/macOS):
    ```bash
    g++ lab_1.cpp -o lab1_program
    ```
    If using an IDE like Visual Studio or Code::Blocks, you can open `lab_1.cpp` as part of a project and use the IDE's build/compile functionality.

4.  **Run the compiled executable:**

    On Linux/macOS:
    ```bash
    ./lab1_program
    ```
    On Windows (if compiled with MinGW/G++ or similar):
    ```bash
    lab1_program.exe
    ```
    The program will likely execute tests for each implemented function, possibly prompting for input or using pre-defined test cases in the `main()` function.

## File Structure (within `Lab_1_functions`)

-   `lab_1.cpp`: Contains the C++ source code with implementations for all tasks and a `main()` function for testing.
-   `README.md`: This file.

## Author

Andrey Potekhin

## License

This project is part of a larger repository for educational purposes and does not have a specific license for this individual lab beyond the main repository's intent.
