#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if (i < n) {
                st.push(idx);
            }
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}