#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    cout << solution.sumSubarrayMins(arr) << endl;

    return 0;
}