#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        int n = nums.size();
        const long long MOD = 1e9 + 7;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        stack<int> st;
        long long maxProduct = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int minIndex = st.top();
                st.pop();
                
                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;
                
                long long subarraySum = prefix[right + 1] - prefix[left];
                long long product = subarraySum * nums[minIndex];
                
                maxProduct = max(maxProduct, product);
            }
            st.push(i);
        }
        
        return maxProduct % MOD;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2};
    cout << sol.maxSumMinProduct(nums) << endl; // Output: 14
    return 0;
}