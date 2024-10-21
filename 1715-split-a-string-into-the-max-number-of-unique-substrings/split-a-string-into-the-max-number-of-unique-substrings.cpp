class Solution {
public:
    int backtrack(int start, unordered_set<string>&seen, string s){
        if(start == s.size()) return 0;
        int maxsplits = 0;
        for(int i = start + 1; i <= s.size(); ++i){
            string substring = s.substr(start, i-start);
            if(seen.find(substring) == seen.end()){
                seen.insert(substring);
                maxsplits = max(maxsplits, 1 + backtrack(i, seen, s));
                seen.erase(substring);
            }
        }
        return maxsplits;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        return backtrack(0,seen, s);
    }
};