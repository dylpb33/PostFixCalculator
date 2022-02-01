/*
	postfix_calculator.cpp

	Implementation of the postfix calculator.
*/

#include "postfix_calculator.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool postfix_calculator::evaluate(string expr) {


    istringstream ss(expr); //Create istringstream object.
    string str; //Create string to store each substring.
    double number; //Declare number as  a double.

    //Takes in each substring
    while (ss >> str) {
        //Checks if each substring is an operator. If it is not an operator then it is
        //converted to a double and added to the stack.
        if (str != "+" && str != "-" && str != "*" && str != "/"){
            number = stod(str);
            rpnStack.push(number);
        }

        //If substring is an operator, then the input calculation is carried out.
        else{

            //Returns false if query causes a stack underflow situation.
            if(rpnStack.empty() || rpnStack.size() == 1){
                return false;
            }

            //Gets the two operands from the top of the stack so that calculations
            //can be performed with them.
            _num1 = rpnStack.top();
            rpnStack.pop();
            _num2 = rpnStack.top();
            rpnStack.pop();

            //Performs calculation on the two operands based on the provided operator.
            if (str == "+") {
                _answer = _num2 + _num1;
            } else if (str == "-") {
                _answer = _num2 - _num1;
            } else if (str == "*") {
                _answer = _num2 * _num1;
            } else {
                _answer = _num2 / _num1;
            }
            //Adds the resulting answer back to the stack.
            rpnStack.push(_answer);
        }

    }
    return true;
}


void postfix_calculator::clear(){
    //Clears stack until it is empty.
    while(!rpnStack.empty()){
        rpnStack.pop();
    }
    //Clears copy of the stack until it is empty.
    while (!copy.empty()){
        copy.pop();
    }
}

//Returns the number at the top of the stack, if the stack is empty, then function returns 0.0
double postfix_calculator::top(){
    if(rpnStack.empty()){
        return 0.0;
    }
    else{
        return rpnStack.top();
    }
}

//Returns the copy of the stack to display the stacks elements.
std::string postfix_calculator::to_string(){
   copy = rpnStack;
   string stackCopy;
    for (int i = 0; i < rpnStack.size(); ++i) {
        stackCopy = stackCopy + '\n' + ::to_string(copy.top());
        copy.pop();
    }
    return stackCopy;
}

//Default constructor
postfix_calculator::postfix_calculator(){
    _answer = 0;
}

