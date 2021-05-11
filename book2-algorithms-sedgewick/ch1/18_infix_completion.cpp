#include <iostream>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string expression = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
    string corrected;

    map<string, string> parentheses;
    parentheses[")"] = "(";
    parentheses["]"] = "[";
    parentheses["}"] = "{";

    string token;
    istringstream ss(expression);
    queue<string> q;
    while (ss >> token) {
        if (token == ")" || token == "]" || token == "}") {
            while (!q.empty()) {
                corrected += q.front() + " ";
                q.pop();
            }
            corrected = parentheses[token] + " " + corrected + token + " ";
        } else
            q.push(token);
    }

    cout << expression << endl;
    cout << corrected << endl;

    return 0;
}