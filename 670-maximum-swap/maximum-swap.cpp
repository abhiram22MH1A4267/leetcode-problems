class Solution {
public:
    int maximumSwap(int num) {
        string val = to_string(num);
        int l = -1, r = -1, maxidx = -1, maxdgt = -1;
        for(int i = val.length()-1; i >= 0; i--){
            if(val[i] - '0' > maxdgt){
                maxdgt = val[i] - '0';
                maxidx = i;
            }
            else if(val[i] - '0' < maxdgt){
                l = i;
                r = maxidx;
            }
        }
        if(l == -1) return num;
        swap(val[l], val[r]);
        return stoi(val);
    }
};