class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        int n = skills.size(), n_2 = n/2;
        long long sum = accumulate(skills.begin(), skills.end(), 0LL);
        if((sum % n_2) != 0) return -1;
        int team_skills = sum / n_2;
        sort(skills.begin(), skills.end());
        long long ans = 0;
        for(int i = 0; i < n_2; i++){
            long long l = skills[i], r = skills[n-1-i];
            if((l+r) != team_skills) return -1;
            ans += (l*r);
        }
        return ans;
    }
};