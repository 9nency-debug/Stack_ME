#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < n; j++) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0'}
};
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}