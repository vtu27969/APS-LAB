#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    // Helper function to transfer elements from input to output stack when output is empty
    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from the front of queue and returns it.
    int pop() {
        transfer();
        int topVal = output.top();
        output.pop();
        return topVal;
    }
    
    // Get the front element.
    int peek() {
        transfer();
        return output.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */