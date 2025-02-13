class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(auto i : nums){
            pq.push(i);
        }
        while(!pq.empty() && pq.top() < k){
            long long int first = pq.top();
            pq.pop();
            long long int second = pq.top();
            pq.pop();
            long long int num = 2 * (min(first, second)) + max(first, second);
            pq.push(num);
            ans++;
        }
        return ans;
    }
};