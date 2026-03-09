#include <iostream>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;              // will store potential '3' values
        int third = INT_MIN;        // best candidate for '2'

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // nums[i] is the potential '1'
            if (nums[i] < third) return true;

            // Pop all elements smaller than nums[i] and update 'third'
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            // Push current as potential '3'
            st.push(nums[i]);
        }
        return false;
    }
};
int main () {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.find132pattern(nums) << endl; // Output: false

    nums = {3, 1, 4, 2};
    cout << sol.find132pattern(nums) << endl; // Output: true

    nums = {-1, 3, 2, 0};
    cout << sol.find132pattern(nums) << endl; // Output: true

    return 0;
}