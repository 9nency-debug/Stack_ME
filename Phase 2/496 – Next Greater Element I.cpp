#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> ans;

        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                ans[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        while (!st.empty()) {
            ans[st.top()] = -1;
            st.pop();
        }

        vector<int> final;
        for (int x : nums1) {
            final.push_back(ans[x]);
        }
            return final;
    }
};
int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 2, 1, 4};
    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}