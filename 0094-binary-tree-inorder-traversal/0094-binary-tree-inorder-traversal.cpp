#include <vector>
#include <stack>

using namespace std;

// Remove this struct since it's already defined in the included header file.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;

        while (current != nullptr || !nodeStack.empty()) {
            // Traverse to the leftmost node while pushing nodes into the stack
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }

            // At this point, current is nullptr, so we pop a node from the stack
            current = nodeStack.top();
            nodeStack.pop();

            // Add the current node's value to the result
            result.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        return result;
    }
};

