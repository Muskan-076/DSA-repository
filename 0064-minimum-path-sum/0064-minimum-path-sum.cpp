// space optimized DP O(m × n) time, O(n) space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        dp[0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++)
            dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {

            // First column
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};


// memoization 
// class Solution {
// public:
//     int minsumpath(int i, int j,int m ,int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
       
//         if(i == m-1 && j== n-1){
//             return grid[i][j];
//         }
//         if(i > m-1 || j > n-1){
//             return INT_MAX;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int ans = min(minsumpath(i, j+1,m,n, grid, dp) , minsumpath(i+1, j, m, n, grid, dp) );

//         if(ans == INT_MAX){
//             return dp[i][j] = INT_MAX;
//         }
        
//         return dp[i][j] = grid[i][j] + ans;
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return minsumpath(0,0,m ,n, grid, dp);
//     }
// };