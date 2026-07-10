//Time: O(n × amount) Space: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {

                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

//Time: O(n × amount) Space: O(n × amount)

// class Solution {
// public:
//     int numberofcoins(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
//         if (amount == 0)
//             return 0;

//         if(i == coins.size()) return 1e9;

//         if (dp[i][amount] != -1)
//             return dp[i][amount];

//         int take = 1e9;

//         if (coins[i] <= amount)
//             take = 1 + solve(i, coins, amount - coins[i],  dp);
        
//         int notTake = solve(i + 1, amount, coins, dp);
//         return dp[i][amount] = min(take, notTake);


        
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         int ans = solve(0, amount, coins, dp);

//         return ans >= 1e9 ? -1 : ans;
        
//     }
// };