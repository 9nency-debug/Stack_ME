#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *nextNode) {
        val = x;
        next = nextNode;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;

        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            vals.push_back(cur->val);
        }

        int n = vals.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[i] > vals[st.top()]) {
                ans[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {

    Solution sol;

    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    vector<int> result = sol.nextLargerNodes(head);

    cout << "Next Greater Nodes: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}