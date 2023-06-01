#include <stdio.h>
 // piecewise recurrence relation can be implemented with the following methods.
 
 // 1. Looping
 // 2. Recursion
 // 3. Dynamic Programming  


//1. Looping Method with for loop
int piecewiseForLoop(int n) {           // begins the function with a parameter n 
    int f0 = 0, f1 = 1, f2 = 2, fn;      // initializes the variables f0, f1, f2, and fn with their respective values
    if (n == 0) {                       // checks if the input n is 0
        return f0;                     // returns f0 if n is 0
    } else if (n == 1) {                // checks if the input n is 1
        return f1;                     // returns f1 if n is 1
    } else if (n == 2) {                // checks if the input n is 2
        return f2;                     // returns f2 if n is 2
    } else {                            // executes the block if n is greater than or equal to 3
        for (int i = 3; i <= n; i++) {  // iterates through the loop from i=3 to n
            fn = f0 + f1;               // computes the value of fn using the values of f0 and f1
            f0 = f1;                    // updates the values of f0, f1, and f2 for the next iteration
            f1 = f2;
            f2 = fn;
        }
        return fn;                      // returns the final value of fn, which is equal to F(n)
    }
}



// 2. Recursion Method
int piecewiseRecursion(int n) {      // function definition with parameter n
    if (n == 0) {                   // checks if n is equal to 0
        return 0;                  // returns 0 if n is 0
    } else if (n == 1) {            // checks if n is equal to 1
        return 1;                  // returns 1 if n is 1
    } else if (n == 2) {            // checks if n is equal to 2
        return 2;                  // returns 2 if n is 2
    } else {                        // if n is greater than 2
        return piecewiseRecursion(n-3) + piecewiseRecursion(n-2);    // computes the value of F(n) using the recurrence relation and recursion
    }
}


// 3.  Dynamic Programming Method
int piecewiseDynamicProgramming(int n) {  // function definition with parameter n
   
   // a common technique in dynamic programming where solutions to subproblems are stored in memory so they can be reused later.
   
    int f[n+1];                          // creates an integer array f with size n+1
    f[0] = 0;                            // sets the first element of f to 0
    f[1] = 1;                            // sets the second element of f to 1
    f[2] = 2;                            // sets the third element of f to 2
    for (int i = 3; i <= n; i++) {       // for loop that iterates through i=3 to i=n
        f[i] = f[i-3] + f[i-2];          // computes the value of f[i] using the recurrence relation and stores it in the array
    }
    return f[n];                         // returns the value of f[n], which is equal to F(n)
}





int main() {
    
    
     printf("Result for index three:\n");
     
     printf("Result Loop: %d\n",piecewiseForLoop(3));
     printf("Result dynamic programming: %d\n",piecewiseDynamicProgramming(3));
     printf("Result Recursion: %d\n\n",piecewiseRecursion(3));
     
     
     
     printf("Result for index four:\n");
     printf("Result Loop: %d\n",piecewiseForLoop(4));
     printf("Result dynamic  programming: %d\n",piecewiseDynamicProgramming(4));
     printf("Result Recursion: %d\n\n",piecewiseRecursion(4));
     
     
     
     printf("Result for index five:\n");
     printf("Result Loop: %d\n",piecewiseForLoop(5));
     printf("Result dynamic programming: %d\n",piecewiseDynamicProgramming(5));
     printf("Result Recursion: %d\n\n",piecewiseRecursion(5));
     
     
     printf("Result for index six:\n");
     printf("Result Loop: %d\n",piecewiseForLoop(6));
     printf("Result dynamic programming: %d\n",piecewiseDynamicProgramming(6));
     printf("Result Recursion: %d\n\n",piecewiseRecursion(6));
     
     
     printf("Result for index seven:\n");
     printf("Result Loop: %d\n",piecewiseForLoop(7));
     printf("Result dynamic programming: %d\n",piecewiseDynamicProgramming(7));
     printf("Result Recursion: %d\n\n",piecewiseRecursion(7));
     
      
    return 0;
}
