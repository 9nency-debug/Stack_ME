#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();

        if (topNode->right != nullptr) {
            pushLeft(topNode->right);
        }

        return topNode->val;
    }
};

int main() {

    // Creating a sample BST
    //        7
    //      /   \
    //     3     15
    //          /  \
    //         9    20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator obj(root);

    cout << "BST elements in sorted order: ";

    while (obj.hasNext()) {
        cout << obj.next() << " ";
    }

    return 0;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */