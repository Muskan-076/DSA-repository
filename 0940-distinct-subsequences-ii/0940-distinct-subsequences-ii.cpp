class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences including empty
        long long dp = 1;

        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp) % MOD;

            // Remove duplicates caused by previous occurrence of c
            newDp = (newDp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};