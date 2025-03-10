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
    map<int, vector<pair<int,int>>>mp;
    void Traversal(TreeNode* root, int bf, int level){
        if(!root) return;
        mp[bf].push_back({level, root->val});
        Traversal(root->left, bf-1, level+1);
        Traversal(root->right, bf+1, level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp = {};
        Traversal(root, 0, 0);

        vector<vector<int>>ans;
        for(auto it : mp){
            vector<int>vec;
            sort(it.second.begin(), it.second.end());
            for(auto i : it.second){
                vec.push_back(i.second);
                // cout<<i.first<<" "<<i.second<<endl;
            }
            ans.push_back(vec);
        }
        return ans;
    }
};