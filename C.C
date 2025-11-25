#include <stdio.h>

/*
 * FUNCTION PROTOTYPES (DECLARATIONS)
 *
 * These tell the compiler:
 *   - the function name
 *   - the return type
 *   - the parameter types
 * before main uses them.
 */

// Returns the sum of all elements in an integer array.
int sum_array(const int *arr, int size);

// Fills an integer array with a given value.
void fill_array(int *arr, int size, int value);

// Prints all elements of an integer array.
void print_array(const int *arr, int size);

/*
 * main FUNCTION
 *
 * General structure of a function:
 *   return_type function_name(parameter_list) {
 *       // local variables
 *       // statements
 *       // loops, conditionals, etc.
 *       // return statement (if return_type is not void)
 *   }
 */

int main(void) {                      // return type: int
                                      // function name: main
                                      // parameter list: void (no parameters)
    // Local variables inside main
    int numbers[5];                   // array of 5 ints (uninitialized)
    int length = 5;                   // local variable
    int total;                        // will hold the sum

    // Call fill_array to put values into the array.
    // Here we pass:
    //   - numbers      as int *   (array name decays to pointer)
    //   - length       as int
    //   - 7            as int value to fill with
    fill_array(numbers, length, 7);

    // Print array contents
    print_array(numbers, length);

    // Call sum_array and store the returned value in 'total'
    total = sum_array(numbers, length);

    printf("Sum of array elements: %d\n", total);

    // Example of using a pointer to go through the same array
    int *ptr = numbers;              // pointer to int, points to first element
    printf("Using a pointer to visit each element:\n");
    for (int i = 0; i < length; i++) {   // loop inside main
        // *(ptr + i) is pointer arithmetic form of numbers[i]
        printf("  Element %d via pointer: %d\n", i, *(ptr + i));
    }

    // Return value of main
    // This matches the return type 'int' of the function.
    return 0;
}

/*
 * FUNCTION DEFINITION: fill_array
 *
 * Parts:
 *   1) Return type: void     (does not return a value)
 *   2) Function name: fill_array
 *   3) Parameter list:
 *        - int *arr   (pointer to int, used as array parameter)
 *        - int size   (number of elements)
 *        - int value  (value to store)
 *   4) Function body: everything inside { }
 */

void fill_array(int *arr, int size, int value) {
    // Local variable inside this function
    int i;

    // Classic for loop
    for (i = 0; i < size; i++) {
        // arr[i] uses array indexing
        // This is the same as *(arr + i) using pointer arithmetic.
        arr[i] = value;
    }

    // No return statement here because the return type is void.
    // The array is modified through the pointer 'arr'.
}

/*
 * FUNCTION DEFINITION: sum_array
 *
 * Return type: int
 *   This function will give back an int (the sum of elements).
 *
 * Parameters:
 *   - const int *arr   pointer to constant int (function will not change values)
 *   - int size         number of elements in the array
 */

int sum_array(const int *arr, int size) {
    int i;               // loop variable
    int sum = 0;         // local variable that accumulates the sum

    // Loop from index 0 to size - 1
    for (i = 0; i < size; i++) {
        // arr[i] reads an element from the array
        sum += arr[i];
        // same as: sum += *(arr + i);
    }

    // Return the computed sum to the caller
    return sum;
}

/*
 * FUNCTION DEFINITION: print_array
 *
 * Return type: void
 *   It only prints the array for display. It does not return a value.
 */

void print_array(const int *arr, int size) {
    int i;                      // local loop variable

    printf("Array contents: [");

    // Loop to print every element
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);

        // Print comma and space between elements, but not after the last one
        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}
