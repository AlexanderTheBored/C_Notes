/*
    DECLARATIONS IN C
    From SIMPLE to MEDIUM
    - variables
    - arrays
    - pointers
    - function prototypes (function declarations)
*/

#include <stdio.h>   // We use printf in the examples

/* ===========================
 * LEVEL 1: SIMPLE DECLARATIONS
 * =========================== */

int main(void) {
    /* 
       BASIC VARIABLE DECLARATIONS
       ---------------------------
       Pattern:  type  name;
    */

    int x;           // declare an int named x (uninitialized)
    float y;         // declare a float named y
    char letter;     // declare a char named letter

    /*
       DECLARATION + INITIALIZATION
       ----------------------------
       Pattern:  type  name = value;
    */

    int age = 18;          // declare and initialize age with value 18
    float pi = 3.14f;      // declare and initialize pi with 3.14 (f = float literal)
    char grade = 'A';      // declare and initialize a char with 'A'

    /* We can use printf to show initialized values: */
    printf("LEVEL 1:\n");
    printf("age = %d\n", age);
    printf("pi = %f\n", pi);
    printf("grade = %c\n\n", grade);


    /* ===========================
     * LEVEL 2: ARRAY DECLARATIONS
     * =========================== */

    /*
        ARRAY DECLARATION
        -----------------
        Pattern:  type  name[size];

        This reserves a block of memory for 'size' elements of the given type.
    */

    int numbers[5];        // array of 5 ints, elements are uninitialized
    float scores[3];       // array of 3 floats

    /*
        We can also combine declaration with initialization.
    */

    int primes[4] = {2, 3, 5, 7};   // array of 4 ints with initial values
    char name[6]   = "Rovel";       // char array with a string (extra space for '\0')

    /*
        Let's initialize some of the arrays manually.
    */
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    scores[0] = 95.5f;
    scores[1] = 88.0f;
    scores[2] = 72.25f;

    printf("LEVEL 2:\n");
    printf("numbers: %d %d %d %d %d\n",
           numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    printf("primes:  %d %d %d %d\n",
           primes[0], primes[1], primes[2], primes[3]);
    printf("name:    %s\n\n", name);


    /* ===========================
     * LEVEL 3: POINTER DECLARATIONS
     * =========================== */

    /*
        POINTER DECLARATION
        -------------------
        Pattern:  type *name;

        This does not store a value directly.
        It stores the ADDRESS of a value of that type.
    */

    int *ptr;        // pointer to int (currently uninitialized, points nowhere valid)
    float *fptr;     // pointer to float
    char *cptr;      // pointer to char

    /*
        We usually make a pointer point to an existing variable using '&' (address-of).
        Example: ptr = &x;  (ptr now stores the address of x)
    */

    x = 42;          // give x a value so we can point to it
    ptr = &x;        // ptr now points to x

    /*
        DEREFERENCING
        -------------
        *ptr  means "go to the address stored in ptr and read the value there".

        So if ptr = &x, then *ptr is the same as x.
    */

    printf("LEVEL 3:\n");
    printf("x = %d\n", x);           // direct access
    printf("*ptr (value at address stored in ptr) = %d\n\n", *ptr);


    /* ===========================
     * LEVEL 4: FUNCTION DECLARATIONS (PROTOTYPES)
     * =========================== */

    /*
        NOTE:
        In real code, function prototypes usually go ABOVE main.
        For the sake of "one file demo", we'll declare them here as comments,
        but their real prototypes are actually written below and used by the compiler
        before linking.

        Example of function declaration (prototype):

            int add(int a, int b);

        - int      → return type
        - add      → function name
        - (int a, int b) → parameter list (types + names)
        - ;        → ends the declaration (no body here)
    */

    /* We will actually call some functions that are declared below via prototypes. */

    /* Call a simple function that takes no parameters and returns nothing. */
    say_hello();   // declaration (prototype) will be above, definition below main

    /* Call a function that adds two ints and returns the result. */
    int sum_result = add(3, 4);   // 3 and 4 are arguments
    printf("LEVEL 4:\n");
    printf("add(3, 4) = %d\n", sum_result);

    /* Call a function that computes the sum of an int array. */
    int arr_sum = sum_array(primes, 4);  // primes is an int array of size 4
    printf("sum_array(primes, 4) = %d\n\n", arr_sum);

    /*
        PROGRAM END
    */
    return 0;
}

/* ===========================
 * FUNCTION PROTOTYPES (DECLARATIONS)
 * These usually appear ABOVE main.
 * I'm placing them here for clarity in this example.
 * In a real file, move these lines to the top (before main).
 * =========================== */

/*
    Simple function that takes no parameters and returns nothing.
*/
void say_hello(void);

/*
    Function that takes two ints and returns their sum as int.
*/
int add(int a, int b);

/*
    Function that takes:
      - const int *arr  → a pointer to an array of int (read-only)
      - int size        → how many elements to sum
    and returns:
      - int             → the sum of the elements
*/
int sum_array(const int *arr, int size);


/* ===========================
 * FUNCTION DEFINITIONS (BODIES)
 * =========================== */

/* Definition of say_hello (matches: void say_hello(void);) */
void say_hello(void) {
    printf("say_hello(): Hello from a function!\n");
}

/* Definition of add (matches: int add(int a, int b);) */
int add(int a, int b) {
    int result;          // declaration of local variable
    result = a + b;      // add the two parameters
    return result;       // return the result to the caller
}

/* Definition of sum_array (matches its prototype) */
int sum_array(const int *arr, int size) {
    int sum = 0;         // accumulator
    int i;               // loop counter

    for (i = 0; i < size; i++) {
        sum += arr[i];   // add each element to sum
    }

    return sum;          // final sum
}
