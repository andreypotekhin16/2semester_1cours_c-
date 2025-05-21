# Lab 2: Sorting Algorithms and Complexity Analysis

This project focuses on the implementation and empirical analysis of three common sorting algorithms: Bubble Sort, Insertion Sort, and Merge Sort. The primary goal is to study and apply methods for analyzing algorithm complexity by measuring their practical performance on datasets of varying sizes.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Objective

To study and apply methods for analyzing the complexity of algorithms.

## Tasks

1.  **Algorithm Implementation:**
    Implement the following sorting algorithms in C++:
    *   Bubble Sort
    *   Insertion Sort
    *   Merge Sort

2.  **Empirical Time Analysis:**
    *   Conduct an empirical analysis of the runtime performance for each implemented sorting algorithm.
    *   Test with arrays of different sizes (e.g., 100, 1000, 10000 elements). The actual sizes used for testing are defined within the program.
    *   The analysis involves measuring the time taken by each algorithm to sort these arrays.
    *   Arrays are typically filled with random or pseudo-random numbers for testing purposes.

## Key Concepts Implemented/Learned

-   **Sorting Algorithms:**
    -   **Bubble Sort:** A simple comparison-based algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
    -   **Insertion Sort:** Builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
    -   **Merge Sort:** A divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves.
-   **Algorithm Complexity:** Understanding the theoretical time complexity (e.g., O(n^2) for Bubble/Insertion, O(n log n) for Merge) and observing it through empirical measurements.
-   **Time Measurement:** Using C++ features (e.g., `<chrono>` library) to accurately measure the execution time of code segments.
-   **Data Generation:** Creating test datasets (arrays of varying sizes with potentially random values).
-   **Comparative Analysis:** Comparing the performance of different algorithms under similar conditions.
-   **Dynamic Memory Allocation:** (Potentially used, especially for Merge Sort or for creating arrays of variable sizes).
-   **Recursion:** Utilized in the implementation of Merge Sort.

## Technologies Used

-   **Programming Language:** C++
-   **Compiler:** Any standard C++ compiler (e.g., G++, Clang, MSVC)
-   **Standard Libraries:**
    -   `<iostream>` for input/output.
    -   `<vector>` (likely used for dynamic arrays).
    -   `<algorithm>` (potentially for `std::generate` or `std::shuffle` if used for data prep, or `std::copy` in Merge Sort).
    -   `<chrono>` for time measurement.
    -   `<random>` for generating random numbers for array initialization.

## How to Compile and Run

1.  **Clone the main repository (if you haven't already):**
    ```bash
    git clone https://github.com/andreypotekhin16/2semester_1cours_c-.git
    ```

2.  **Navigate to this lab's directory:**
    ```bash
    cd 2semester_1cours_c-/Lab_2_algoritm
    ```

3.  **Compile the C++ source file (`lab_2.cpp`).**
    You might need to specify a C++ standard that supports `<chrono>` and `<random>` (e.g., C++11 or newer).

    Using G++ (common on Linux/macOS):
    ```bash
    g++ -std=c++11 lab_2.cpp -o sorting_analysis
    ```
    (Replace `sorting_analysis` with your desired executable name if you prefer).
    If using an IDE like Visual Studio or Code::Blocks, ensure your project settings use a C++11 (or later) standard, then open `lab_2.cpp` and use the IDE's build/compile functionality.

4.  **Run the compiled executable:**

    On Linux/macOS:
    ```bash
    ./sorting_analysis
    ```
    On Windows (if compiled with MinGW/G++ or similar):
    ```bash
    sorting_analysis.exe
    ```
    The program will likely execute each sorting algorithm on arrays of predefined sizes and print the execution time (e.g., in milliseconds or microseconds) for each algorithm and dataset size.

## Expected Outcome / Analysis

The primary outcome of this lab is to observe and compare the practical performance of the different sorting algorithms. You should expect to see:
-   **Merge Sort** significantly outperforming Bubble Sort and Insertion Sort, especially on larger datasets, reflecting its `O(n log n)` average and worst-case time complexity.
-   **Bubble Sort** and **Insertion Sort** exhibiting `O(n^2)` behavior, meaning their execution time will grow quadratically with the input size, making them much slower for larger arrays.
-   Insertion Sort might perform slightly better than Bubble Sort on average for smaller or partially sorted datasets, but both will be much slower than Merge Sort on large random datasets.

The output of the program should clearly present the time taken for each algorithm on each tested array size, allowing for easy comparison.

## File Structure (within `Lab_2_algoritm`)

-   `lab_2.cpp`: Contains the C++ source code for the sorting algorithms, timing mechanisms, data generation, and the main program logic for testing.
-   `README.md`: This file.

## Author

Andrey Potekhin

## License

This project is part of a larger repository for educational purposes and does not have a specific license for this individual lab beyond the main repository's intent.
