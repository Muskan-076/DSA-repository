class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n;
    vector<int> nums;
    int dp[201][201][201];

    int solve(int idx, int g1, int g2) {
        if (idx == n)
            return (g1 == g2 && g1 != 0);

        int &ans = dp[idx][g1][g2];
        if (ans != -1) return ans;

        ans = 0;

        // Skip
        ans = solve(idx + 1, g1, g2);

        // Put in seq1
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, ng1, g2)) % MOD;

        // Put in seq2
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, ng2)) % MOD;

        return ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};