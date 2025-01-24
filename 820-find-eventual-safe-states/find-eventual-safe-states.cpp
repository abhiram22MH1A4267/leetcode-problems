class Solution {
public:
    int n;
    vector<int>degreein;
    vector<vector<int>>rGraph;
    vector<int>ans;

    void init(vector<vector<int>>&Graph){
        n = Graph.size();
        degreein = vector<int>(n,0);
        rGraph.resize(n, vector<int>(0));

        for(int i = 0; i < n; i++){
            for(int edge : Graph[i]){
                rGraph[edge].push_back(i);
                degreein[i]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(degreein[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int x1 = q.front();
            q.pop();
            ans.push_back(x1);
            for(int i : rGraph[x1]){
                degreein[i]--;
                if(degreein[i] == 0) q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};