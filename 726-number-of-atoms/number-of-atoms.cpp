class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int>mp;
        string result;
        int count = 0, multiple = 1;
        stack<int>count_st;
        for(int i = formula.size()-1; i >= 0; i--){
            if(isalpha(formula[i]) && islower(formula[i])){
                int length = 2;
                i--;
                while(i >= 0 && islower(formula[i])){
                    i--;
                    length++;
                }
                string atom = formula.substr(i,length);
                mp[atom] += max(count,1)*multiple;
                count = 0;
            }
            else if(isalpha(formula[i]) && isupper(formula[i])){
                string atom(1,formula[i]);
                mp[atom] += max(count,1)*multiple;
                count = 0;
            }
            else if(isdigit(formula[i])){
                count = formula[i]-'0';
                int power = 10;
                while(i-1 >= 0 && isdigit(formula[i-1])){
                    count += power * (formula[--i] - '0');
                    power *= 10;
                }
            }
            else if(formula[i] == ')'){
                count_st.push(multiple);
                multiple *= max(count,1);
                count = 0;
            }
            else{
                multiple = count_st.top();
                count_st.pop();
            }
        }
        for(auto [atom,count] : mp){
            result += atom;
            if(count > 1){
                result += to_string(count);
            }
        }
        return result;
    }
};