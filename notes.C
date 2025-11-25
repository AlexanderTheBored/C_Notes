/*
    This is a complete C program that shows:

      - how functions are declared and defined
      - how arrays work
      - how pointers work with arrays
      - how loops work

    I added very heavy comments to explain almost every word and symbol.
*/

#include <stdio.h>   /* 
                        #include    → preprocessor directive, tells the compiler to include another file
                        <stdio.h>   → standard input/output header, gives access to printf, scanf, etc.
                     */

/*
    FUNCTION PROTOTYPES (DECLARATIONS)

    A "prototype" tells the compiler:

      - the function name
      - the return type
      - the parameter types

    before the function is actually used in main.

    Syntax pattern:

      return_type  function_name(parameter_type1 parameter_name1, ...);

    It ends with a semicolon because this is only a declaration, not the body.
*/

/* 
   int → return type (function will give back an int value)
   sum_array → function name
   (const int *arr, int size) → parameter list
*/
int sum_array(const int *arr, int size);

/*
   void → return type (function does not return any value)
   fill_array → function name
   (int *arr, int size, int value) → parameters
*/
void fill_array(int *arr, int size, int value);

/*
   void → no return value
   print_array → function name
   (const int *arr, int size) → parameters
*/
void print_array(const int *arr, int size);


/*
    main FUNCTION

    This is the entry point of every C program. When you run the program,
    execution starts from main.

    Syntax:

      int main(void) { ... }

    - int  → return type, main returns an integer to the operating system
    - main → function name (special)
    - (void) → parameter list (no parameters)
    - { ... } → function body (code that main executes)
*/

int main(void) {                     /* 
                                        int    → main returns an integer
                                        main   → function name
                                        (void) → no parameters
                                     */

    /* Local variable declarations inside main */

    int numbers[5];                  /* 
                                        int        → type of each element (integer)
                                        numbers    → array name
                                        [5]        → this array has 5 elements

                                        This line reserves contiguous memory for 5 int values.
                                        Valid indexes: 0, 1, 2, 3, 4
                                     */

    int length = 5;                  /* 
                                        int      → variable type
                                        length   → variable name
                                        = 5      → assignment, store value 5 into 'length'
                                     */

    int total;                       /* 
                                        int   → type
                                        total → variable name, will hold sum of elements later
                                     */

    /*
        Call fill_array to put values into the array.

        function call syntax:

          function_name(argument1, argument2, ...);

        Here we pass:
          numbers → array name, which "decays" to a pointer to its first element (int *)
          length  → number of elements
          7       → value that we want to store in each element
    */
    fill_array(numbers, length, 7);

    /*
        Call print_array to display the contents of the array.
    */
    print_array(numbers, length);

    /*
        Call sum_array and store the returned value in 'total'.

        total = sum_array(numbers, length);

        - sum_array(numbers, length) calls the function
        - the function returns an int
        - that int is stored in the variable 'total'
    */
    total = sum_array(numbers, length);

    /*
        printf is a function from stdio.h that prints formatted text.

        "Sum of array elements: %d\n" → format string
        %d                            → placeholder for an int
        total                         → value that will replace %d
    */
    printf("Sum of array elements: %d\n", total);

    /*
        POINTER EXAMPLE

        int *ptr = numbers;

        - int *  → type: pointer to int
        - ptr    → variable name
        - = numbers

        'numbers' as an expression (not with [index]) becomes a pointer to
        the first element of the array (equivalent to &numbers[0]).
    */
    int *ptr = numbers;

    printf("Using a pointer to visit each element:\n");

    /*
        for loop syntax:

          for (initialization; condition; increment) {
              // loop body
          }

        Here:

          int i = 0        → start i at 0 (first index)
          i < length       → loop while i is less than 5
          i++              → increment i by 1 each iteration
    */
    for (int i = 0; i < length; i++) {

        /*
            *(ptr + i) is called "pointer arithmetic" and dereferencing.

            ptr       → pointer to int (points to some memory address)
            ptr + i   → move i elements forward in the array
                         (because each int has a fixed size, the compiler
                         calculates the correct address)

            * (ptr + i) → dereference operator *, which means "get the value
                           stored at this address"

            So:

                *(ptr + i)   is equivalent to   numbers[i]
        */
        printf("  Element %d via pointer: %d\n", i, *(ptr + i));
    }

    /*
        return 0;

        - return → keyword, sends a value back from the function
        - 0      → integer literal

        main returns 0 to signal that the program ended successfully
        to the operating system.
    */
    return 0;
}

/*
    FUNCTION DEFINITION: fill_array

    Pattern:

      return_type function_name(parameter_list) {
          // local variables
          // statements
      }

    Here:

      - return type: void      (no value returned)
      - function name: fill_array
      - parameters:
            int *arr  → pointer to int, represents an array of integers
            int size  → number of elements to process
            int value → value to store in each element
*/

void fill_array(int *arr, int size, int value) {

    int i;   /* local variable, will be used as a loop counter */

    /*
        Classic for loop:

            for (i = 0; i < size; i++)

        - i = 0      → start at first index
        - i < size   → continue while i is less than size
        - i++        → increase i by 1 each time
    */
    for (i = 0; i < size; i++) {

        /*
            arr[i] uses "array index" notation.

            Because arr is a pointer to int, arr[i] is defined as:

                *(arr + i)

            So we are writing:

                arr[i] = value;

            meaning "store 'value' into the i-th element of the array."
        */
        arr[i] = value;
    }

    /*
        No return statement is required with a value because the function
        return type is void.

        The array is modified indirectly through the pointer 'arr'. Since
        'arr' points to the original memory, the changes are visible in main.
    */
}

/*
    FUNCTION DEFINITION: sum_array

    Signature:

      int sum_array(const int *arr, int size)

    - int        → return type, we return an int sum
    - sum_array  → function name
    - const int *arr → parameter, pointer to constant int
                        "const" means this function promises not to modify
                        the values pointed to by arr
    - int size   → number of elements to sum
*/

int sum_array(const int *arr, int size) {

    int i;          /* loop counter */
    int sum = 0;    /* local variable to accumulate the sum, starts at 0 */

    /*
        Loop from index 0 up to size - 1.

        On each iteration:

           sum += arr[i];

        means:

           sum = sum + arr[i];
    */
    for (i = 0; i < size; i++) {
        sum += arr[i];   /* read value from array and add to sum */
        /* same as: sum += *(arr + i);  using pointer arithmetic */
    }

    /*
        return sum;

        Sends the final sum back to the caller (in this case, main).
        This matches the return type "int" in the function declaration.
    */
    return sum;
}

/*
    FUNCTION DEFINITION: print_array

    Signature:

      void print_array(const int *arr, int size)

    - void          → no value returned
    - print_array   → function name
    - const int *arr → pointer to constant int (we only read, not modify)
    - int size      → number of elements to print
*/

void print_array(const int *arr, int size) {

    int i;   /* loop counter */

    printf("Array contents: [");

    /*
        Loop through all elements and print them one by one.

        We use arr[i] to access the i-th element.
    */
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);   /* print the current element as an integer */

        /*
            If this is not the last element, print a comma and a space.
            This keeps the output clean, like: [7, 7, 7, 7, 7]
        */
        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");   /* close the bracket and go to the next line */
}
