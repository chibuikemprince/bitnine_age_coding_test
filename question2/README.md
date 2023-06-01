### Looping, recursion, and dynamic programming are methods used to implement the piecewise recurrence relation in question 2

 # Here are some advantages and disadvantages of each method:

## 1. Looping: 

### Advantages: 
- Loops are simple to write and easy to understand, making them a good choice for small-scale problems.
- Looping can be more memory efficient than other methods since it doesn't require additional space for function call stacks.

### Disadvantages:
- For large-scale problems, looping can take a long time to compute and may require a lot of memory.
- Loops can be difficult to optimize if the relation is complex, requiring additional effort.


## 2. Recursion: 

### Advantages: 
- Recursion can be an elegant and intuitive way to write code that mirrors the problem definition.
- Recursion can be easier to read and debug since it more closely mirrors how we think about solving problems.

### Disadvantages:
- Recursion can be slow and memory-intensive since it requires creating and managing multiple call stacks.
- Recursion may lead to stack overflow errors for large-scale problems.

## 3. Dynamic Programming:

### Advantages:
- Dynamic programming can be an efficient way to solve even very large-scale problems.
- Dynamic programming can reduce duplication of computations by storing and reusing previously computed values, reducing runtime and memory requirements.

### Disadvantages:
- Dynamic programming may require additional space for the memoization table or array used to store previously computed values.
- Dynamic programming may require restructuring the code to fit the requirements of the technique.



In general, the choice of method will depend on the specific problem being solved and the scale of the problem. For smaller scale problems, looping or recursion may be sufficient, while larger-scale problems will require dynamic programming or other more efficient techniques.

The advantages of using dynamic programming approach is that it avoids redundant computations by storing intermediate results in an array which can be reused and also allows us to compute the value of F(n) in linear time. However, it requires additional space to store the intermediate results in an array.

Between the three implementations, using the for loop and dynamic programming approach are generally faster and less likely to cause a stack overflow error compared to recursion. Recursion has the advantage of being more concise and easier to understand