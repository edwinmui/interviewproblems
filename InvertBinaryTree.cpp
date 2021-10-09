/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    /*
    Recursive solution
    // base cases
        if (!root) return NULL;
        if (!root->left && !root->right) return root;
        // if has two children
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    */
public:
    TreeNode* invertTree(TreeNode* root) {
        // Iterative solution
        if (!root) return NULL;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            TreeNode* next_node = q.front();
            q.pop_front();
            TreeNode* temp = next_node->left;
            next_node->left = next_node->right;
            next_node->right = temp;
            if (next_node->left) q.push_back(next_node->left);
            if (next_node->right) q.push_back(next_node->right);
        }
        return root;
    }
};
