#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        long long sumMax = 0, sumMin = 0;
        stack<int> st;

        // ---------- SUM OF MINIMUMS ----------
        vector<int> prevSmaller(n), nextSmaller(n);

        // Previous Smaller (strict)
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Smaller (non-strict)
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            sumMin += (long long)nums[i] * left * right;
        }

        vector<int> prevGreater(n), nextGreater(n);

        // Previous Greater (strict)
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Greater (non-strict)
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            sumMax += (long long)nums[i] * left * right;
        }

        return sumMax - sumMin;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.subArrayRanges(nums) << endl; // Output: 4

    nums = {1, 3, 3};
    cout << sol.subArrayRanges(nums) << endl; // Output: 4

    nums = {4, -2, -3, 4, 1};
    cout << sol.subArrayRanges(nums) << endl; // Output: 59

    return 0;
}