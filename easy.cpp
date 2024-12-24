#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
    stack<char> stk;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } 
        else {
            if (stk.empty()) return "NO";
            char top = stk.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                stk.pop(); 
            } else {
                return "NO";
            }
        }
    }
    return stk.empty() ? "YES" : "NO";
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    while (n--) {
        string s;
        getline(cin, s); 
        cout << isBalanced(s) << endl;
    }

    return 0;
}
