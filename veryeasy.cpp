#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> dataStack; 
    stack<int> minStack;    

public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    void push(int val) {
        dataStack.push(val);
        minStack.push(min(val, minStack.top()));
    }
    void pop() {
        if (!dataStack.empty()) {
            dataStack.pop();
            minStack.pop();
        }
    }

    int top() {
        if (!dataStack.empty()) {
            return dataStack.top();
        }
        return -1; 
    }
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; 
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; 

    minStack.pop();
    cout << "Top: " << minStack.top() << endl;        
    cout << "Minimum: " << minStack.getMin() << endl;

    return 0;
}
