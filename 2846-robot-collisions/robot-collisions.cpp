class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& heights, string directions) {
        vector<pair<int,int>>v;
        int n = positions.size();
        for(int i = 0; i < n; i++){
            v.push_back({positions[i],i});
        }
        sort(v.begin(), v.end());
        stack<int>st;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int index = v[i].second;
            if(directions[index] == 'L'){
                if(st.empty()){
                    ans.push_back(index);
                }
                else{
                    while(!st.empty() && heights[st.top()] < heights[index]){
                        st.pop();
                        heights[index]--;
                    }
                    if(st.empty()) ans.push_back(index);
                    else{
                        if(heights[st.top()] == heights[index]) st.pop();
                        else{
                            heights[st.top()]--;
                            if(heights[st.top()] == 0) st.pop();
                        }
                    }
                }
            }
            else{
                st.push(index);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            ans[i] = heights[ans[i]];
        }
        return ans;
    }
};