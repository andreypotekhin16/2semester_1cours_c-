# Lab 5: Advanced Class Features and Operator Overloading in C++

This project delves deeper into Object-Oriented Programming (OOP) in C++ by exploring concepts such as constant members, static members, friend functions, friend classes, and operator overloading. Several distinct classes are implemented to demonstrate these features.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Tasks / Features Implemented

The `main.cpp` (and any associated header/source files) includes the implementation and demonstration of the following:

1.  **`Student` Class:**
    *   **Members:**
        *   Full Name (FIO - Фамилия Имя Отчество) (e.g., `std::string`).
        *   Group Number (e.g., `std::string` or `int`).
        *   Year of Birth (declared as a `const` member, initialized in the constructor's initializer list).
    *   **Methods:** Constructor(s), methods to display student information.
    *   **Demonstration:** Examples of creating and using `Student` objects.

2.  **`GeometricShape` Class:**
    *   **Members:**
        *   Type of shape (e.g., `char`: 'o' - circle, 'k' - square, 't' - triangle, etc.).
        *   Dimensions necessary to calculate area (e.g., radius for circle, side for square, base/height for triangle - potentially using a union or variant, or separate classes inherited from a base `GeometricShape` if polymorphism were introduced, but the task implies a single class).
    *   **Methods:**
        *   Constructor(s).
        *   Destructor.
        *   Method to calculate the area of the shape based on its type and dimensions.
    *   **Static Members:**
        *   A `static int` member to count the number of `GeometricShape` objects created.
        *   A `static` function to display the current count of created objects.

3.  **Segment Length Calculation with Friend Function:**
    *   Assumes a `CPoint` class (e.g., for 2D points with `x` and `y` coordinates) is defined or available.
    *   **Two functions** to calculate the length of a segment defined by two `CPoint` objects:
        *   One regular (non-member, non-friend) function that uses public getter methods of `CPoint` (if coordinates are private).
        *   One function declared as a `friend` to the `CPoint` class, allowing it direct access to private members of `CPoint` objects.
    *   **Explanation:** Discussion of the implementation differences and access privileges for friend vs. non-friend functions.

4.  **`PersonName` and `Car` Classes with Friend Class:**
    *   **`PersonName` Class:**
        *   **Members:** Last Name, First Name, Patronymic (Middle Name) (e.g., `std::string`). These members are likely `private`.
        *   **Methods:** Constructor, display methods.
    *   **`Car` Class:**
        *   **Members:** Owner's Full Name (an object of `PersonName`), Year of Manufacture, etc.
        *   **Methods:** Constructor, display methods.
        *   **Friendship:** The `Car` class (or specific methods within it) is declared as a `friend` of the `PersonName` class to allow it direct access to the private name components of its `PersonName` owner object for processing or display.

5.  **`CVector` Class (1D Integer Array) with Operator Overloading:**
    *   **Members:** Pointer to a dynamically allocated integer array, size of the array.
    *   **Methods:** Constructor(s), destructor (to deallocate memory), methods for access, display.
    *   **Overloaded Operators:**
        *   `=` (Assignment operator - deep copy).
        *   `+` (Vector addition - element-wise).
        *   `-` (Vector subtraction - element-wise).
        *   `*` (Scalar multiplication or dot product, depending on interpretation. Element-wise with another vector is also possible).
        *   `/` (Scalar division or element-wise division by another vector, with checks for division by zero).
        *   (Likely `[]` for element access).

6.  **`CMatrix` Class (Real Number Matrix) with Operator Overloading:**
    *   **Members:** Pointer to a dynamically allocated 2D array (or array of arrays) of `double` or `float`, number of rows, number of columns.
    *   **Methods:** Constructor(s), destructor, methods for access, display.
    *   **Overloaded Operators:**
        *   `=` (Assignment operator - deep copy).
        *   `+` (Matrix addition).
        *   `-` (Matrix subtraction).
        *   `*` (Matrix multiplication or scalar multiplication).
        *   `/` (Scalar division).
        *   (Potentially `()` for element access `matrix(row, col)`).

7.  **`ComplexNumber` Class with Operator Overloading:**
    *   **Members:** Real part, imaginary part (e.g., `double`).
    *   **Methods:** Constructor(s), display method (e.g., "a + bi").
    *   **Overloaded Standard Operators:**
        *   `+` (Complex addition).
        *   `-` (Complex subtraction).
        *   `*` (Complex multiplication).
        *   `/` (Complex division).
        *   `=` (Assignment).
        *   `==`, `!=` (Equality/inequality).
        *   `<<` (Stream insertion for `std::cout`).
        *   `>>` (Stream extraction for `std::cin`).

## Key Concepts Implemented/Learned

-   **`const` Member Variables:** Declaring members whose values cannot be changed after initialization.
-   **`static` Member Variables:** Variables shared among all instances of a class.
-   **`static` Member Functions:** Functions that can be called on the class itself, not on a specific instance, and can only access static members.
-   **`friend` Functions:** Non-member functions granted special access to `private` and `protected` members of a class.
-   **`friend` Classes:** Entire classes granted special access to `private` and `protected` members of another class.
-   **Operator Overloading:** Defining custom behavior for standard C++ operators (e.g., `+`, `-`, `*`, `/`, `=`, `[]`, `<<`, `>>`) when used with objects of user-defined classes.
-   **Dynamic Memory Management:** Using `new` and `delete` (or `new[]` and `delete[]`) for `CVector` and `CMatrix` classes.
-   **The Rule of Three/Five/Zero:** (Implicitly important for classes managing dynamic memory like `CVector` and `CMatrix`) - proper implementation of copy constructor, copy assignment operator, and destructor (and move constructor/assignment if using C++11 and later).
-   **Object Composition:** One class containing an object of another class as a member (e.g., `Car` containing `PersonName`).

## Technologies Used

-   **Programming Language:** C++
-   **Standard C++ Libraries:**
    -   `<iostream>` for console input/output.
    -   `<string>` for string manipulation.
    -   `<vector>` (potentially as an alternative internal storage for `CVector` or `CMatrix`, or for demonstrations).
    -   `<cmath>` for mathematical functions (e.g., for segment length).
    -   `<stdexcept>` for error handling (e.g., in matrix/vector operations).
    -   `<iomanip>` for formatted output.

## How to Compile and Run

1.  **Clone the main repository (if you haven't already):**
    ```bash
    git clone https://github.com/andreypotekhin16/2semester_1cours_c-.git
    ```

2.  **Navigate to this lab's directory:**
    ```bash
    cd 2semester_1cours_c-/Lab_5_class
    ```

3.  **Compile the C++ source file(s) (e.g., `main.cpp`).**
    A C++11 or newer standard is highly recommended, especially for classes managing dynamic resources and for a cleaner coding style.

    Using G++ (common on Linux/macOS):
    ```bash
    g++ -std=c++11 main.cpp -o lab5_advanced_classes_app
    ```
    (Replace `lab5_advanced_classes_app` with your desired executable name).
    If you have split your code into multiple `.cpp` and `.h` files, compile them together:
    ```bash
    g++ -std=c++11 main.cpp YourClass1.cpp YourClass2.cpp -o lab5_advanced_classes_app
    ```
    If using an IDE like Visual Studio or Code::Blocks, add all relevant source files to your project and use the IDE's build/compile functionality.

4.  **Run the compiled executable:**

    On Linux/macOS:
    ```bash
    ./lab5_advanced_classes_app
    ```
    On Windows (if compiled with MinGW/G++ or similar):
    ```bash
    lab5_advanced_classes_app.exe
    ```
    The program will execute the `main()` function, which should contain demonstrations of each implemented class, its features, and the overloaded operators.

## File Structure (within `Lab_5_class`)

-   `main.cpp`: (Likely) Contains most or all class definitions and the `main()` function for demonstration.
-   (Potentially other `.h` and `.cpp` files if you've separated class definitions and implementations).
-   `README.md`: This file.

## Author

Andrey Potekhin

## License

This project is part of a larger repository for educational purposes and does not have a specific license for this individual lab beyond the main repository's intent.
