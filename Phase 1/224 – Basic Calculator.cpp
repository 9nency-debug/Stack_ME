#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    long long calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

private:
    long long helper(const string& s, int& i) {
        stack<long long> st;
        long long num = 0;
        int sign = 1;

        while (i < s.length()) {
            char c = s[i];

            if (isdigit(c)) {
                num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                st.push(sign * num);
                num = 0;
                continue;
            }
            else if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                i++;  // skip '('
                long long val = helper(s, i);
                st.push(sign * val);
            }
            else if (c == ')') {
                break;
            }

            i++;
        }

        long long res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
int main() {
    string s;
    getline(cin,s);
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}