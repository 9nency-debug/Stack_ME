#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (char ch : str) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main() {
    Solution sol;
    string str = "{[()]}";
    bool result = sol.isValid(str);
    cout << (result ? "Valid" : "Invalid") << endl;
    return 0;
}
