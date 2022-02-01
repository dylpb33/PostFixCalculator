/*
	calculator_main.cpp

	Provides the user interface for the postfix calculator.

*/

#include <iostream>
#include <string>
#include "postfix_calculator.h"

using namespace std;

int main() {
    postfix_calculator calc;
    string input;

    cout << "Welcome to the postfix calculator!" << endl;
    cout << "----------------------------------" << endl;
    while (true) {
        cout << "Input string:" << endl;
        getline(cin, input);

        if (input == "quit") {
            return 0;
        }
        else if (input == "clear") {
            calc.clear();
        }
        else if (input == "debug") {
            cout << "DEBUG MODE:" << endl;
            cout << "Stack contains: " << endl;
            cout << calc.to_string() << endl;
        }
        else {
            bool success = calc.evaluate(input);
            if (success) {
                cout << "answer: " << calc.top() << endl;
            } else {
                cout << "ERROR: Stack underflow." << endl;
            }
        }

        cout << "----------------------------------" << endl;
    }

    return 0;
}
