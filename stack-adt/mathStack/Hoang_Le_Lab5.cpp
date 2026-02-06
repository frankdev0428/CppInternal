#include <iostream>
#include "MathStack.h"
using namespace std;

int main()
{
    MathStack stack(10);
    double result;
    // Expression 1
    // 12 3 / 4 2 * + 6 3 / -
    cout << "Expression 1:\n12 3 / 4 2 * + 6 3 / -\n";

    try {
        stack.push(12);
        stack.push(3);
        stack.div();

        stack.push(4);
        stack.push(2);
        stack.mult();

        stack.add();

        stack.push(6);
        stack.push(3);
        stack.div();

        stack.sub();

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR\n";
    }

    stack.clear();
    // Expression 2
    // 7 2 3 * + 8 4 / 5 - *
    
    cout << "\nExpression 2:\n7 2 3 * + 8 4 / 5 - *\n";

    try {
        stack.push(7);
        stack.push(2);
        stack.push(3);
        stack.mult();
        stack.add();

        stack.push(8);
        stack.push(4);
        stack.div();

        stack.push(5);
        stack.sub();

        stack.mult();

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR\n";
    }

    stack.clear();
    // Expression 3
    // 5 10 5 5 - / +
  
    cout << "\nExpression 3:\n5 10 5 5 - / +\n";

    try {
        stack.push(5);
        stack.push(10);
        stack.push(5);
        stack.push(5);
        stack.sub();      // 5 - 5 = 0
        stack.div();      // division by zero
        stack.add();

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR: Division by zero.\n";
    }

    stack.clear();
    // Expression 4
    // 3 8 4 2 2 - / * +
    cout << "\nExpression 4:\n3 8 4 2 2 - / * +\n";

    try {
        stack.push(3);
        stack.push(8);
        stack.push(4);
        stack.push(2);
        stack.push(2);
        stack.sub();      // 2 - 2 = 0
        stack.div();      // division by zero
        stack.mult();
        stack.add();

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR: Division by zero.\n";
    }

    stack.clear();

    // =========================
    // Expression 5
    // 6 2 / 3 4 multAll
    // =========================
    cout << "\nExpression 5:\n6 2 / 3 4 multAll\n";

    try {
        stack.push(6);
        stack.push(2);
        stack.div();      // 3

        stack.push(3);
        stack.push(4);
        stack.multAll();  // 3 * 3 * 4 = 36

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR\n";
    }

    stack.clear();

    // =========================
    // Expression 6
    // 3 4 5 addAll 2 3 * addAll
    // =========================
    cout << "\nExpression 6:\n3 4 5 addAll 2 3 * addAll\n";

    try {
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.addAll();   // 12

        stack.push(2);
        stack.push(3);
        stack.mult();     // 6

        stack.addAll();   // 12 + 6 = 18

        stack.pop(result);
        cout << "Result: " << result << endl;
    }
    catch (...) {
        cout << "Result: ERROR\n";
    }

    return 0;
}