# Lab 4: Introduction to Classes in C++

This project focuses on understanding and implementing fundamental concepts of Object-Oriented Programming (OOP) in C++ by creating several distinct classes. Each class encapsulates data and behavior related to a specific entity or concept. All implementations are contained within `main.cpp`.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Tasks / Features Implemented

The `main.cpp` file includes the implementation and demonstration of the following classes and functions:

1.  **`CPoint3D` Class (3D Point):**
    *   **Members:** `x, y, z` coordinates (doubles or floats).
    *   **Methods:**
        *   Constructor(s).
        *   Destructor.
        *   Method to set coordinate values.
        *   Method to display point information.
    *   **Demonstration:** Creation and usage of multiple `CPoint3D` objects.

2.  **Device State Class (e.g., `DeviceStateGenerator`):**
    *   **State:** An integer value from 0 to 126.
    *   **Update Rule:** `x(n+1) = (a * x(n) + b) mod 127`, where `a = 10`, `b = 11`.
    *   **Methods:**
        *   Constructor (to initialize state).
        *   Function to transition the device to its next state.
        *   Function to display the current state.

3.  **Element-wise Sum and Difference for `CPoint` Objects:**
    *   **Note:** This task refers to a `CPoint` class. It's assumed this is a 2D point class (e.g., with `x` and `y` coordinates) that needs to be defined, or `CPoint3D` is used and operations are performed on its `x, y, z` components. The functions perform:
        *   `CPoint_sum = CPoint1 + CPoint2` (element-wise)
        *   `CPoint_diff = CPoint1 - CPoint2` (element-wise)
    *   These are implemented as free functions or potentially overloaded operators.

4.  **`CCircle` Class (Circle):**
    *   **Members:**
        *   Radius.
        *   Center coordinates (e.g., using a `CPoint` object or separate `x_center`, `y_center` members).
    *   **Methods:**
        *   Set radius.
        *   Calculate circumference (`2 * PI * radius`).
        *   Calculate area (`PI * radius * radius`).
    *   **Demonstration:** Application of the `CCircle` class.

5.  **`Monster` Class:**
    *   **Members:** Age, health, strength, defense (integers).
    *   **Methods:**
        *   Constructor.
        *   Function to display all monster information.
        *   `attack(Monster& targetMonster)`: Deals random damage (1 to monster's strength) to the target.
        *   `takeDamage(int damageAmount)`: Reduces monster's health by `(damageAmount - defense)`, ensuring health doesn't go below zero.
    *   **Demonstration:** Simulation of a battle between two monster objects.

6.  **`Segment` Class (Line Segment):**
    *   **Members:** Two points representing the start and end of the segment (e.g., two `CPoint` or `CPoint3D` objects).
    *   **Methods:**
        *   Calculate the length of the segment.

7.  **Distance Between Two `CPoint` Objects:**
    *   A free function that takes two `CPoint` objects as parameters and returns the Euclidean distance between them.

8.  **Area of a `CCircle` Object:**
    *   A free function that takes a `CCircle` object as a parameter and returns its area. (This might be an alternative to the class method in Task 4, or a specific requirement to have it as a free function).

## Key Concepts Implemented/Learned

-   **Class Definition:** Declaring classes with member variables (attributes) and member functions (methods).
-   **Object Instantiation:** Creating objects (instances) of classes.
-   **Constructors:** Special methods for initializing objects.
-   **Destructors:** Special methods for cleaning up resources when objects are destroyed.
-   **Encapsulation:** Bundling data and methods that operate on the data within a single unit (the class).
-   **Access Specifiers:** Using `public`, `private` (and `protected` if applicable, though likely not for this lab) to control access to class members.
-   **Member Functions:** Implementing setters, getters, and other utility methods.
-   **Object Interaction:** Objects of one class interacting with objects of another (e.g., `Monster` attacking another `Monster`).
-   **Composition:** Classes containing objects of other classes as members (e.g., `Segment` containing `CPoint` objects, `CCircle` potentially containing a `CPoint` for its center).
-   **Free Functions Operating on Objects:** Writing standalone functions that take class objects as parameters.
-   **Mathematical Formulas:** Implementing geometric calculations (distance, length, circumference, area) and state update rules.
-   **Random Number Generation:** Using `rand()` for the monster attack simulation.

## Technologies Used

-   **Programming Language:** C++
-   **Standard C++ Libraries:**
    -   `<iostream>` for console input/output.
    -   `<cmath>` for mathematical functions like `sqrt`, `pow`, and `M_PI` (or defining PI).
    -   `<cstdlib>` and `<ctime>` for `rand()` and `srand()` (for random number generation).
    -   `<vector>` (if used for storing collections of objects, though not explicitly required by tasks).
    -   `<iomanip>` (potentially for formatted output).

## How to Compile and Run

1.  **Clone the main repository (if you haven't already):**
    ```bash
    git clone https://github.com/andreypotekhin16/2semester_1cours_c-.git
    ```

2.  **Navigate to this lab's directory:**
    ```bash
    cd 2semester_1cours_c-/Lab_4_class
    ```

3.  **Compile the C++ source file (`main.cpp`).**
    A C++11 or newer standard is recommended for modern features, though this lab might compile with older standards.

    Using G++ (common on Linux/macOS):
    ```bash
    g++ -std=c++11 main.cpp -o lab4_classes_app
    ```
    (Replace `lab4_classes_app` with your desired executable name if you prefer).
    If using an IDE like Visual Studio or Code::Blocks, you can open `main.cpp` as part of a project (or as a single file) and use the IDE's build/compile functionality.

4.  **Run the compiled executable:**

    On Linux/macOS:
    ```bash
    ./lab4_classes_app
    ```
    On Windows (if compiled with MinGW/G++ or similar):
    ```bash
    lab4_classes_app.exe
    ```
    The program will execute the `main()` function, which should demonstrate the creation and usage of objects from all the implemented classes, printing relevant information and simulation results to the console.

## File Structure (within `Lab_4_class`)

-   `main.cpp`: Contains the C++ source code for all class definitions (`CPoint3D`, `DeviceStateGenerator`, `CPoint` , `CCircle`, `Monster`, `Segment`) and the `main()` function used for demonstrating their functionality.
-   `README.md`: This file.

## Author

Andrey Potekhin

## License

This project is part of a larger repository for educational purposes and does not have a specific license for this individual lab beyond the main repository's intent.
