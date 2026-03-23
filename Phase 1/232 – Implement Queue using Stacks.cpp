#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
    private:
        stack<int> input;
        stack<int> output;

    public:
        MyQueue() {

        }

        void push(int x) {
            input.push(x);
        }

        int pop() {
            if (output.empty()) {
                while(!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }

            int val = output.top();
            output.pop();
            return val;
        }
        int peek() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }

            return output.top();
        }

        bool empty() {
            return input.empty() && output.empty();
        }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << boolalpha << myQueue.empty() << endl; // return false 

    return 0;
}