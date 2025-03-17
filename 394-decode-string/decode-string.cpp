class Solution {
public:
    vector<int> GetValue(string &s, int index){
        int val = 0, i = 0;
        while(index >= 0 && isdigit(s[index])){
            val += (s[index] - '0') * pow(10, i);
            index--;
            i++;
        }
        return {val, index+1};
    }
    string decodeString(string s) {
        stack<string>st;
        int n = s.length();
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '['){
                string s1 = "";
                while(!st.empty() && st.top() != "]"){
                    s1 += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                vector<int>vec = GetValue(s, i-1);
                int val = vec[0];
                i = vec[1];
                string s2 = "";
                for(int j = 0; j < val; j++){
                    s2 += s1;
                }
                st.push(s2);
            }
            else{
                st.push(string(1, s[i]));
                
            }

        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};