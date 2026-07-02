/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     bool val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(bool x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(bool x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool helper(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;

        if((!p && q) || (p && !q)) return false;
        if(p->val != q->val) return false;

        bool left = helper(p->left, q->left);

        bool right= helper(p->right, q->right);

        if(right == false || left == false) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};