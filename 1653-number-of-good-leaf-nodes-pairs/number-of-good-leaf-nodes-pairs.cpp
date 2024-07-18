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
    int ans = 0;
    vector<int> dfs(TreeNode* root, int distance){
        if(!root) return {};
        if(root->left == NULL && root->right == NULL){
            return {1};
        }
        vector<int>leftDistance = dfs(root->left,distance);
        vector<int>rightDistance = dfs(root->right, distance);
        for(int l : leftDistance){
            for(int r : rightDistance){
                if(l+r <= distance) ans++;
            }
        }
        vector<int>currDistance;
        for(int l : leftDistance){
            if(l+1 < distance) currDistance.push_back(l+1);
        }
        for(int r : rightDistance){
            if(r+1 < distance) currDistance.push_back(r+1);
        }
        return currDistance;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }
};