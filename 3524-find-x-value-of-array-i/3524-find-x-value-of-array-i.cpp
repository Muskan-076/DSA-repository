class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);
        
        // dp[r] = number of subarrays ending at the previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int x : nums) {
            
            vector<long long> cur(k, 0);

            int rem = x % k;

            // Start a new subarray with only x
            cur[rem]++;

            // Extend all previous subarrays by x
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                cur[newRem] += dp[r];
            }

            // Add current subarrays to the final answer
            for (int r = 0; r < k; r++) {
                ans[r] += cur[r];
            }

            // Current becomes previous
            dp = cur;
        }

        return ans;
    }
};