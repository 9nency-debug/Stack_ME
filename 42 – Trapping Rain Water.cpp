#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;   
        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if (st.empty()) break;

                int left = st.top();
                int distance = i - left - 1;
                int boundedHeight = min(height[left], height[i]) - height[bottom];

                water += distance * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};
int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << solution.trap(height) << endl;

    return 0;
}