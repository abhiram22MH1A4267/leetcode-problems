class Solution {
public:
    bool isConnected(int a, int b, unordered_map<int,vector<int>>&mp){
        unordered_set<int>vis;
        stack<int>st;
        st.push(a);

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(vis.count(node)) continue;
            vis.insert(node);

            if(node == b) return true;

            for(int edges : mp[node]){
                st.push(edges);
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if(mp.count(a) && mp.count(b) && isConnected(a, b, mp)){
                return edge;
            }
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        return {};
    }
};