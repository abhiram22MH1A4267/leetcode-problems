class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int n = items.size(), m = queries.size();
        vector<unsigned long long> priceIdx(n);
        for(int i=0; i<n; i++)
            priceIdx[i]=((unsigned long long)items[i][0]<<32)+i;
        sort(priceIdx.begin(), priceIdx.end());

        vector<int> mostBeauty(n);
        mostBeauty[0] = items[priceIdx[0]&UINT_MAX][1];
        // Build up the mostBeauty array
        for (int i = 1; i < n; i++)
            mostBeauty[i] = max(mostBeauty[i-1], items[priceIdx[i]&UINT_MAX][1]);

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int query = queries[i];
            unsigned long long target=((unsigned long long)query<<32)+UINT_MAX;
            // Use upper_bound to find the first item with a price > query
            int j = upper_bound(priceIdx.begin(), priceIdx.end(), target)-priceIdx.begin();
            // If j is 0, no items have price <= query
            if (j == 0) ans[i] = 0;
            else ans[i] = mostBeauty[j-1];
        }
        return ans;
    }
};