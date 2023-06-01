#include <stdio.h>
#include <stdlib.h>

// Definition of enum for different types of operations
typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO,
    VALUE
} TypeTag;

// Definition of Node struct for binary tree
typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Helper function to create Node
Node *makeFunc(TypeTag type, Node *left, Node *right) {
    // Allocate memory for new node
    Node *node = malloc(sizeof(Node));
    // Initialize node's variables
    node->type = type;
    node->left = left;
    node->right = right;
    // Return the new node
    return node;
}

// Helper function to create a value Node
Node *makeValueNode(int value) {
    // Create a new node with the VALUE type tag
    Node *node = makeFunc(VALUE, NULL, NULL);
    // Set the node's value
    node->value = value;
    // Return the new node
    return node;
}

// Helper function to create a Fibonacci Node
Node *makeFiboNode(Node *arg) {
    // Create a new node with the FIBO type tag and the provided argument node as its left child
    return makeFunc(FIBO, arg, NULL);
}

// Function to calculate the nth Fibonacci number
int fibo(int n) {
    // Initialize the base cases
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    // Iterate through the remaining values to calculate the nth Fibonacci number
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    // Return the nth Fibonacci number
    return fib[n];
}

// Function to recursively evaluate the operations represented by the binary tree
int evaluate(Node *node) {
    // Check the type of the current node and evaluate the corresponding operation based on its type and child nodes
    switch (node->type) { 
        case ADD: // If the type is ADD, evaluate the left and right child nodes recursively and sum their values
            return evaluate(node->left) + evaluate(node->right);
        case SUB: // If the type is SUB, evaluate the left and right child nodes recursively and subtract their values
            return evaluate(node->left) - evaluate(node->right);
        case MUL: // If the type is MUL, evaluate the left and right child nodes recursively and multiply their values
            return evaluate(node->left) * evaluate(node->right);
        case DIV: // If the type is DIV, evaluate the left and right child nodes recursively and divide their values
            return evaluate(node->left) / evaluate(node->right);
        case FIBO: // If the type is FIBO, evaluate the left child node recursively and calculate the corresponding Fibonacci number
            return fibo(evaluate(node->left));
        case VALUE: // If the type is VALUE, return the node's value
            return node->value;
        default: // If the type is not recognized, return 0
            return 0;
    }
}


void calc(Node *node) {
    printf("%d\n", evaluate(node));
}


/**
* Finally, in the main function, 
* several Node objects are created and 
* passed to the calc function to be evaluated and printed:
*/
int main() {
    Node *add = makeFunc(ADD, makeValueNode(10), makeValueNode(6));
    Node *mul = makeFunc(MUL, makeValueNode(5), makeValueNode(4));
    Node *sub = makeFunc(SUB, mul, add);
    Node *fibo = makeFiboNode(sub);
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
    return 0;
}
