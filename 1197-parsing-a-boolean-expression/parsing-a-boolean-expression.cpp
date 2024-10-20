class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(char ch : expression){
            if(ch == ',' || ch == '(') continue;
            if(ch == 't' || ch == 'f' || ch == '&' || ch == '|' || ch == '!'){
                st.push(ch);
            }
            else if(ch == ')'){
                bool hastrue = false, hasfalse = false;
                while(st.top() != '&' && st.top() != '|' && st.top() != '!'){
                    char topValue = st.top();
                    st.pop();
                    if(topValue == 't') hastrue = true;
                    if(topValue == 'f') hasfalse = true;
                }
                char operation = st.top();
                st.pop();
                if(operation == '&'){
                    st.push(hasfalse ? 'f' : 't');
                }
                else if(operation == '|'){
                    st.push(hastrue ? 't' : 'f');
                }
                else if(operation == '!'){
                    st.push(hastrue ? 'f' : 't');
                }
            }
        }
        return st.top() == 't';
    }
};