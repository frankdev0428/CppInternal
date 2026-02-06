// implementation file for the MathStack class
#include "MathStack.h"

//************************************************
// Member function add. add pops                 *
// the first two values off the stack and        *
// adds them. The sum is pushed onto the stack.  *
//************************************************
void MathStack::add(){
    int num, sum;

    // Pop the first two values off the stack.
    pop(num);
    pop(sum);

    // Add the two values, store in sum.
    sum += num;

    // Push sum back onto the stack.
    push(sum);
}

//************************************************
// Member function sub. sub pops the             *
// first two values off the stack. The           *
// first popped value is subtracted from the     *
// second popped value. The difference is pushed *
// onto the stack.                               *
//************************************************
void MathStack::sub(){
    int num, diff;

    // Pop the first two values off the stack.
    pop(num);
    pop(diff);

    // Subtract num from diff.
    diff -= num;

    // Push diff back onto the stack.
    push(diff);

}
void MathStack::mult(){
    int num, prod;

    // Pop the first two values off the stack.
    pop(num);
    pop(prod);

    // Multiply the two values, store in prod.
    prod *= num;

    // Push prod back onto the stack.
    push(prod);
};

void MathStack::div(){
    int num, quot;

    // Pop the first two values off the stack.
    pop(num);   // divisor (first popped)
    pop(quot);  // dividend (second popped)

    // Guard against division by zero.
    if (num == 0) {
        // Define behavior on divide-by-zero: push 0 to avoid crash.
        push(0);
    } else {
        quot /= num;
        push(quot);
    }
};

void MathStack::addAll(){
    int sum, val;

    // If stack is empty, push 0 (no operands).
    if (isEmpty()) {
        push(0);
        return;
    }

    // Start with the first value.
    pop(sum);

    // Add remaining values.
    while (!isEmpty()) {
        pop(val);
        sum += val;
    }

    // Push the total sum back onto the stack.
    push(sum);
};

void MathStack::multAll(){
    int prod, val;

    // If stack is empty, push 0 (no operands).
    if (isEmpty()) {
        push(0);
        return;
    }

    // Start with the first value.
    pop(prod);

    // Multiply remaining values.
    while (!isEmpty()) {
        pop(val);
        prod *= val;
    }

    // Push the total product back onto the stack.
    push(prod);
};