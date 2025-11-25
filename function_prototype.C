/*
    Demo: Function prototypes ABOVE main
    ------------------------------------
    Rule of thumb:
      - Either define your function BEFORE main
      - OR, if the function is defined AFTER main,
        you MUST put a prototype above main.

    In practice, we usually:
      - Put prototypes at the top (or in a header .h file)
      - Put main()
      - Then put function definitions below.
*/

#include <stdio.h>

/* =========================================
 * FUNCTION PROTOTYPES (DECLARATIONS)
 * These are placed ABOVE main.
 * ========================================= */

/*
    int add(int a, int b);

    - int       → return type (function returns an int)
    - add       → function name
    - (int a, int b) → parameter list (two ints)
    - ;         → this is only a prototype, no body yet
*/
int add(int a, int b);

/*
    void say_hello(void);

    - void      → returns nothing
    - say_hello → function name
    - (void)    → takes no parameters
*/
void say_hello(void);


/* =========================================
 * main FUNCTION
 * ========================================= */

int main(void) {
    /* Because the prototypes are above, the compiler
       already knows add() and say_hello() here. */

    say_hello();   // valid: prototype already seen

    int result = add(3, 4);    // valid: compiler knows it returns int
    printf("add(3, 4) = %d\n", result);

    return 0;
}


/* =========================================
 * FUNCTION DEFINITIONS (BODIES)
 * These come AFTER main, but it's okay
 * because we declared prototypes earlier.
 * ========================================= */

/* Matches: void say_hello(void); */
void say_hello(void) {
    printf("Hello from say_hello()!\n");
}

/* Matches: int add(int a, int b); */
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
