class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];

        // dp[i][j] = max score for subarray [i, j] (0-indexed, inclusive)
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of subarray from 2 up to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;
                for (int k = i; k < j; k++) {
                    long long leftSum = prefix[k + 1] - prefix[i];
                    long long rightSum = prefix[j + 1] - prefix[k + 1];
                    int candidate;
                    if (leftSum < rightSum) {
                        candidate = dp[i][k] + (int)leftSum;
                    } else if (leftSum > rightSum) {
                        candidate = dp[k + 1][j] + (int)rightSum;
                    } else {
                        candidate = max(dp[i][k], dp[k + 1][j]) + (int)leftSum;
                    }
                    best = max(best, candidate);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n - 1];
    
    }
};