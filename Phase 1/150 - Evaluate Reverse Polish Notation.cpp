#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {   
    stack<int> st;

    for (string &token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        }
        else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    int n;
    cin >> n;

    vector<string> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    cout << evalRPN(tokens) << endl;

    return 0;
}
