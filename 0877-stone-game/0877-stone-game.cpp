class Solution {
public:

    int solve(int l, int r, vector<int>& piles, vector<vector<int>>&dp){
        if( l == r)
            return piles[l];
        if(dp[l][r] != -1)
            return dp[l][r];
        int takeLeft = 
            piles[l] - solve(l+1, r, piles, dp);
        int takeRight =
            piles[r] - solve(l, r - 1, piles, dp);

        return dp[l][r] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, piles, dp) >= 0;
    }
};
