#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(token);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string path;
    cin >> path;

    Solution sol;
    cout << sol.simplifyPath(path) << "\n";
    return 0;
}