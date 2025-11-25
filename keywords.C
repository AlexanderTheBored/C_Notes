/*
    ===========================
    ANSWER KEY / GLOSSARY
    ===========================

    GENERAL C CONCEPTS
    ------------------
    program           - a collection of instructions written in C that the computer runs
    statement         - a single instruction (usually ends with a semicolon ;)
    keyword           - a reserved word in C with a special meaning (int, void, return, for, etc.)
    identifier        - a name you choose (like main, numbers, sum_array, i, etc.)

    PREPROCESSOR
    ------------
    #include          - preprocessor directive, tells compiler to include another file before compilation
    <stdio.h>         - standard input/output header file, gives access to printf, scanf, etc.

    DATA TYPES
    ----------
    int               - integer type (whole numbers, positive or negative, including 0)
    void              - special type that means "no value" or "nothing returned"
    const             - keyword that means "cannot be changed" inside the function

    VARIABLES
    ---------
    variable          - a named storage location in memory
    declaration       - telling the compiler about a variable or function (its type and name)
    initialization    - giving a variable its first value at the same time you declare it
    assignment        - using = to store a value in a variable   (example: x = 5;)

    ARRAYS
    ------
    array             - a collection of elements of the same type stored in consecutive memory
    int numbers[5];   - declare an array named numbers with 5 integer elements
    index             - position inside the array, starting from 0 up to size - 1
    numbers[i]        - access the element at index i of the array numbers

    POINTERS
    --------
    pointer           - a variable that stores a memory address instead of a direct value
    *                 - in a declaration, it means "pointer to"
                        example: int *ptr;  --> ptr is a pointer to int
    &                 - address-of operator, gets the memory address of a variable (not used in this file but related)
    dereference       - using * in an expression to get the value at an address
                        example: *ptr  means "the value stored at the address in ptr"
    pointer arithmetic- adding an integer to a pointer moves it by that many elements
                        example: ptr + i moves i elements forward in an array
    *(ptr + i)        - dereference of pointer arithmetic, same as array index arr[i]

    FUNCTIONS
    ---------
    function          - a block of code that performs a task and can be called by name
    return type       - type of value the function gives back (int, void, etc.)
    function name     - identifier of the function (main, sum_array, fill_array, print_array)
    parameter list    - variables listed inside parentheses in the function header
                        example: (int size, int value)
    parameter         - variable in the function declaration/definition (a formal input)
    argument          - actual value you pass when calling the function (like 7 in fill_array(..., 7))
    function call     - using function_name(...) to execute the function

    FUNCTION PROTOTYPE
    -------------------
    prototype         - a declaration that tells the compiler:
                            - function name
                            - return type
                            - parameter types
                        written before main
    example           - int sum_array(const int *arr, int size);
                        This line is a prototype (no body, ends with a semicolon).

    MAIN FUNCTION
    -------------
    main              - entry point of the program, execution starts here
    int main(void)    - main returns an int and takes no parameters
    return 0;         - main returns 0 to signal successful program end

    LOOPS AND CONTROL
    -----------------
    for               - loop that repeats a block of code a specific number of times
    for( init; condition; update )
                       - init: runs once at start (int i = 0)
                       - condition: checked before each loop iteration (i < size)
                       - update: runs after each loop iteration (i++)
    i++               - increment operator, same as i = i + 1
    if(condition)     - executes a block of code only if the condition is true
    else              - executes if the previous if condition is false

    STANDARD I/O
    ------------
    printf            - function from stdio.h that prints formatted text
    "%d"              - format specifier for int
    "\n"              - newline character, moves cursor to the next line

    THIS SPECIFIC PROGRAM
    ---------------------
    numbers           - int array of 5 elements
    length            - holds the number of elements in numbers (5)
    total             - holds the sum of the array elements
    ptr               - pointer to int that points to the first element of numbers
    fill_array        - fills all elements of an array with the same value
    sum_array         - adds all elements of the array and returns the total
    print_array       - prints the array in [a, b, c] style format

    KEY EXPRESSIONS
    ---------------
    int numbers[5];           - declare an array of 5 integers
    int *ptr = numbers;       - ptr is a pointer to int, set to point to first element of numbers
    arr[i]                    - i-th element of array arr
    *(ptr + i)                - same as arr[i], but using pointer arithmetic
    total = sum_array(...);   - function call where the return value is assigned to total
    fill_array(numbers, length, 7);
                              - function call passing:
                                - array (as a pointer)
                                - size of the array
                                - value to fill (7)

    Use this as your quick "what is this called / what does this mean" answer key.
*/

/* Preprocessor include giving us printf, etc. */
#include <stdio.h>

/*
    FUNCTION PROTOTYPES
    These tell the compiler what the functions look like before they are used in main.
*/

/* Returns the sum of all elements in an integer array. */
int sum_array(const int *arr, int size);

/* Fills an integer array with a given value. */
void fill_array(int *arr, int size, int value);

/* Prints all elements of an integer array. */
void print_array(const int *arr, int size);


/*
    main FUNCTION
    - Entry point of the program.
    - Returns int.
    - Takes no parameters (void).
*/
int main(void) {

    /* Declare an array of 5 ints. */
    int numbers[5];

    /* Store the length of the array in a variable. */
    int length = 5;

    /* Variable that will hold the sum of array elements. */
    int total;

    /* Fill the array "numbers" with the value 7. */
    fill_array(numbers, length, 7);

    /* Print the contents of the array. */
    print_array(numbers, length);

    /* Compute the sum of the array and store it in total. */
    total = sum_array(numbers, length);

    /* Print the computed sum. */
    printf("Sum of array elements: %d\n", total);

    /* Pointer example: ptr points to the first element of numbers. */
    int *ptr = numbers;

    printf("Using a pointer to visit each element:\n");

    /* Loop through the array using pointer arithmetic. */
    for (int i = 0; i < length; i++) {
        /* *(ptr + i) is the same as numbers[i]. */
        printf("  Element %d via pointer: %d\n", i, *(ptr + i));
    }

    /* Return 0 to signal successful termination. */
    return 0;
}

/*
    FUNCTION: fill_array

    - Fills each element of the array with the given value.
    - arr  is a pointer to int (represents the array).
    - size is the number of elements.
    - value is what we store in each position.
*/
void fill_array(int *arr, int size, int value) {

    int i;  /* loop counter */

    /* Loop from index 0 up to size - 1 and assign value to each element. */
    for (i = 0; i < size; i++) {
        arr[i] = value;   /* same as *(arr + i) = value; */
    }
}

/*
    FUNCTION: sum_array

    - Returns the sum of all elements of the array.
    - arr  is a pointer to const int, meaning we do not change the values.
    - size is the number of elements to sum.
*/
int sum_array(const int *arr, int size) {

    int i;        /* loop counter */
    int sum = 0;  /* accumulator for the sum */

    /* Add each array element to sum. */
    for (i = 0; i < size; i++) {
        sum += arr[i];   /* same as sum += *(arr + i); */
    }

    /* Return the final sum to the caller. */
    return sum;
}

/*
    FUNCTION: print_array

    - Prints the contents of the array in a readable format.
    - arr  is a pointer to const int (we only read, not modify).
    - size is the number of elements to print.
*/
void print_array(const int *arr, int size) {

    int i;  /* loop counter */

    printf("Array contents: [");

    /* Print each element with commas between them. */
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);

        /* Print ", " after each element except the last one. */
        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}
