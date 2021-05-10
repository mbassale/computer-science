#include <stack>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    using namespace std;

    cout << "Dijkstra's Two Stack Algorithm for Expression Evaluation" << endl;

    string expression;
    getline(cin, expression);

    stack<string> operations;
    stack<double> values;

    istringstream ss(expression);
    string token;
    while (ss >> token) {
        if (token == "(") ; // ignore left paren
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "sqrt") operations.push(token); // push operation onto operators stack
        else if (token == ")") { // evaluate expression
            auto op = operations.top();
            operations.pop();
            double val1 = values.top();
            values.pop();
            double val2 = values.top();
            values.pop();
            double res = 0;
            if (op == "+") res = val2 + val1;
            else if (op == "-") res = val2 - val1;
            else if (op == "*") res = val2 * val1;
            else if (op == "/") res = val2 / val1;
            values.push(res);
            cout << val2 << " " << op << " " << val1 << " = " << res << endl;
        } else { // not an operator push a value
            auto value = stod(token);
            values.push(value);
        }
    }

    cout << "Result: " << values.top() << endl;
    return 0;
}