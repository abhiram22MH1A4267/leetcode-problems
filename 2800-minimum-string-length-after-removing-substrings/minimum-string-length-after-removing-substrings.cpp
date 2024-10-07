class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i] == 'D' && st.top() == 'C'){
                st.pop();
            }
            else if(s[i] == 'B' && st.top() == 'A'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
        // string ans = "";
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }
        // return ans.length();
    }
};