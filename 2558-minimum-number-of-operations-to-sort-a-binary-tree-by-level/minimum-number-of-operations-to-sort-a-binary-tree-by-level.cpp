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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int swaps = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int>v(n,0);
            iota(v.begin(), v.end(), 0);
            vector<int>arr(n,0);
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                arr[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sort(v.begin(), v.end(), [&](int i, int j){
                return arr[i] < arr[j];
            });
            for(int i = 0; i < n; ){
                int j = v[i];
                if(j != i){
                    swaps++;
                    swap(v[i], v[j]);
                }
                else i++;
            }
        }
        return swaps;
    }
};