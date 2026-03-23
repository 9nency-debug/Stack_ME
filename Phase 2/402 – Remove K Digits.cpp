#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
int main() {
   
    Solution obj;

    string num = "1432219";
    int k = 3;

    string result = obj.removeKdigits(num, k);

    cout << "Input: " << num << ", k = " << k << endl;
    cout << "Output: " << result << endl;

    return 0;
}
