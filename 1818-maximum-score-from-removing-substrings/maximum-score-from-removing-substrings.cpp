class Solution {
public:
    string subString(string &s, string &target){
        stack<char>st;
        for(auto it : s){
            if(it == target[0] && !st.empty() && st.top() == target[1]){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        string AfterRemove;
        while(!st.empty()){
            AfterRemove += st.top();
            st.pop();
        }
        reverse(AfterRemove.begin(),AfterRemove.end());
        return AfterRemove;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string highPriority = x < y ? "ab" : "ba";
        string lowPriority = highPriority == "ab" ? "ba" : "ab";

        string FirstString = subString(s,highPriority);
        int count = (s.length()-FirstString.length())/2;
        ans += count*max(x,y);

        string SecondString = subString(FirstString,lowPriority);
        count = (FirstString.length()-SecondString.length())/2;
        ans += count*min(x,y);

        return ans;
    }
};