#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (string log : logs) {
            if (log == "../") {
                if (!st.empty()) {
                    st.pop();
                } 
            }
            else if (log == "./") {
                continue;
            }
            else {
                st.push(log);
            }
        }

        return st.size();
    }
};
int main() {
    Solution sol;
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    cout << sol.minOperations(logs) << endl;

    return 0;
}