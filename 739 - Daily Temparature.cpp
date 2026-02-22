#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                answer[prevDay] = i - prevDay;
            }
            st.push(i);
        }
        return answer;
    }
};
int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}