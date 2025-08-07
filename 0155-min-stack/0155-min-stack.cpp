#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> mini;

public:
    MinStack() {
        // No need to initialize anything explicitly
    }
    
    void push(int val) {
        stk.push(val);
        if (mini.empty() || val <= mini.top()) {
            mini.push(val);
        } else {
            mini.push(mini.top());
        }
    }
    
    void pop() {
        if (!stk.empty()) {
            stk.pop();
            mini.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
