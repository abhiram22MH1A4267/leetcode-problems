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
    vector<int>ans;
    void fun(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() < level) ans.push_back(root->val);
        else ans[level-1] = max(ans[level-1], root->val);
        fun(root->left, level+1);
        fun(root->right, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        ans = {};
        fun(root, 1);
        return ans;
    }
};