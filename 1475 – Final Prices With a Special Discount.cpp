#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = 0; i <prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return prices;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> result = sol.finalPrices(prices);

    cout << "Final Prices: ";
    for (int price : result) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}