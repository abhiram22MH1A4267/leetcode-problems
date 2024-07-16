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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string StartPath, EndPath;
        findPath(lca,startValue,StartPath);
        findPath(lca,destValue,EndPath);
        for(auto &it : StartPath){
            it = 'U';
        }
        return StartPath+EndPath;
    }
private:
    TreeNode* findLCA(TreeNode* root, int start, int end){
        if(!root || root->val == start || root->val == end){
            return root;
        }
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right){
            return root;
        }
        return left ? left : right;
    }
    bool findPath(TreeNode* root, int value, string &path){
        if(!root) return false;
        if(root->val == value) return true;
        path.push_back('L');
        if(findPath(root->left, value, path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right, value, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
};