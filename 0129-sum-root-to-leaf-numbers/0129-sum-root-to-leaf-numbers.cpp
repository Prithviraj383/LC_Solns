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
public:
    void helper(TreeNode *root, int x, int &ans){
        if(!root) return;

        x = x*10+root->val;

        if(!root->right && !root->left){
            ans += x;
            return;
        }

        helper(root->left, x, ans);
        helper(root->right, x, ans);
    }
    int sumNumbers(TreeNode* root) {
        int x = 0, ans=0;
        helper(root, x, ans);
        return ans;

    }
};