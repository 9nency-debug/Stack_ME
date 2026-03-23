#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char c : s) {
            if(!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
int main() {
    Solution sol;
    string s = "bacbac";
    cout << sol.removeDuplicates(s) << endl; 
    return 0;
}

// Output: "bacbac"