// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.Implement the MinStack class:

// 1.  MinStack() initializes the stack object.

// 2.  void push(int val) pushes the element val onto the stack.

// 3.  void pop() removes the element on the top of the stack.

// 4.  int top() gets the top element of the stack.

// 5.  int getMin() retrieves the minimum element in the stack.





#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    stack<long long>st;
    long long mn;
    MinStack() {
        mn = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mn = val;
        }
        else if(val > mn) st.push(val);
        else{
            st.push((2LL * val) - mn);
            mn = val;
        }
    }
    
    void pop() {
        if(st.top() < mn) mn = (2LL * mn - st.top());
        st.pop();
    }
    
    int top() {
        if(st.top() <= mn) return (int)mn;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)mn;
    }

    // Constant Time
    // stack<int>st;
    // stack<int>helper;
    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     st.push(val);
    //     if(helper.empty() || val < helper.top()) helper.push(val);
    //     else helper.push(helper.top());
    // }
    
    // void pop() {
    //     st.pop();
    //     helper.pop();
    // }
    
    // int top() {
    //     return st.top();
    // }
    
    // int getMin() {
    //     return helper.top();
    // }

    // Constant Space
    // stack<int>st;
    // stack<int>helper;
    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     st.push(val);
    // }
    
    // void pop() {
    //     st.pop();
    // }
    
    // int top() {
    //     return st.top();
    // }
    
    // int getMin() {
    //     int mn = INT_MAX;
    //     while(!st.empty()){
    //         if(st.top() < mn) mn = st.top();
    //         helper.push(st.top());
    //         st.pop();
    //     }
    //     while(!helper.empty()){
    //         st.push(helper.top());
    //         helper.pop();
    //     }
    //     return mn;
    // }

    // Brute Force
    // stack<int>st;
    // stack<int>helper;
    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     st.push(val);
    // }
    
    // void pop() {
    //     st.pop();
    // }
    
    // int top() {
    //     return st.top();
    // }
    
    // int getMin() {
    //     int mn = INT_MAX;
    //     while(!st.empty()){
    //         if(st.top() < mn) mn = st.top();
    //         helper.push(st.top());
    //         st.pop();
    //     }
    //     while(!helper.empty()){
    //         st.push(helper.top());
    //         helper.pop();
    //     }
    //     return mn;
    // }
};

int main() {
    MinStack* obj = new MinStack();
    
    obj->push(3);
    obj->push(5);
    cout << "Minimum: " << obj->getMin() << endl; // Output: 3
    
    obj->push(2);
    obj->push(1);
    cout << "Minimum: " << obj->getMin() << endl; // Output: 1
    
    obj->pop();
    cout << "Minimum: " << obj->getMin() << endl; // Output: 2
    
    obj->pop();
    cout << "Top: " << obj->top() << endl;        // Output: 5
    cout << "Minimum: " << obj->getMin() << endl; // Output: 3
    
    delete obj;
    return 0;
}