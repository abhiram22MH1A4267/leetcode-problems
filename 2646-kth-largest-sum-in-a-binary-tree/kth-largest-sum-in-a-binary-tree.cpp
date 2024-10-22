class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector<long long int>v;
        queue<TreeNode*>q;
        q.push(root); 
        while(!q.empty()){
            long long int sum=0;
            vector<int>data;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp = q.front();
                q.pop();
                data.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            
            for(auto it:data){
                sum+=it;
            }
            v.push_back(sum);
           
        }
        int n = v.size();
        if(k > n)return -1;
        sort(v.begin(),v.end());
        return v[n-k];
    }
};