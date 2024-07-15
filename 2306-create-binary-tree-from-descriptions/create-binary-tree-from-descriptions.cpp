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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
       unordered_map<int,TreeNode*>mp;
       unordered_set<int>children;
       for(auto it : descriptions){
        int parent = it[0] , child = it[1], is_position = it[2];
        children.insert(child);
        if(mp.find(parent) == mp.end()){
            mp[parent] = new TreeNode(parent);
        }
        if(mp.find(child) == mp.end()){
            mp[child] = new TreeNode(child);
        }
        if(is_position == 1){
            mp[parent]->left = mp[child];
        }
        else{
            mp[parent]->right = mp[child];
        }
       }
       int root = -1;
       for(auto it : descriptions){
        if(children.find(it[0]) == children.end()){
            root = it[0];
            break;
        }
       }
       return mp[root];
    }
};