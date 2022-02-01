/*
	postfix_calculator.h

	Header file for the postfix calculator.
*/

#ifndef _POSTFIX_CALCULATOR_H
#define _POSTFIX_CALCULATOR_H

#include <string>
#include <stack>

using namespace std;


class postfix_calculator {
public:
    bool evaluate(std::string);

    // Remove all items from the current stack.
    void clear();

    // Return the number at the top of the stack (this will be the
    // answer if a valid query was passed to evaluate).  If the
    // stack is empty, returns 0.0.
    double top();

    // Return a string representation of the stack showing all the
    // elements in it.
    std::string to_string();

    // Constructor
    postfix_calculator();


private:
    // TODO: declare member variables here for your stack, etc.
    stack<double> rpnStack; //Declare stack to store the numbers
    stack<double> copy; //Declare a copy of the stack which is used for seeing current stack elements

    //Declares the left hand operand, right hand operand, and resulting answer as doubles.
    double _num1;
    double _num2;
    double _answer;
};

#endif
