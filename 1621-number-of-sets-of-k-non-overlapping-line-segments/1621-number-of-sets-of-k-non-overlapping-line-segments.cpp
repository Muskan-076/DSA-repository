class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        vector<vector<long long>> pref(n, vector<long long>(k + 1));

        // 0 segments -> 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            pref[i][0] = i + 1;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i < n; i++) {

                // Don't use point i as the ending point
                dp[i][j] = dp[i - 1][j];

                // Add a segment ending at i
                dp[i][j] += pref[i - 1][j - 1];
                dp[i][j] %= MOD;

                // Update prefix sum
                pref[i][j] = pref[i - 1][j] + dp[i][j];
                pref[i][j] %= MOD;
            }
        }

        return dp[n - 1][k];
    }
};