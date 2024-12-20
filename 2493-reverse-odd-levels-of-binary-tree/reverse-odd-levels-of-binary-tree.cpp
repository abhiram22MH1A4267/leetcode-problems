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
    map<int,vector<int>>mp;
    void fun(TreeNode* &root, TreeNode* &ans, int level, TreeNode* &head){
        if(root == NULL) return;
        if(level % 2 != 0) swap(root->val, ans->val);
        fun(root->right, ans->left, level+1, head);
        if(root == head) return;
        fun(root->left, ans->right, level+1, head);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* ans = root;
        fun(root, ans, 0, root);
        return ans;
    }
};