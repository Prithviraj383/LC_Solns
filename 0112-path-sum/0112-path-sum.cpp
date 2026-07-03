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

    bool helper(TreeNode *root, int remainingSum){
        if(!root) return false;

        if(!root->left && !root->right) return root->val == remainingSum;

        bool left = helper(root->left, remainingSum - root->val);
        bool right = helper(root->right, remainingSum - root->val);

        if(left == true || right == true) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root, targetSum);
    }
};