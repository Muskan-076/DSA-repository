// using memoization TC=0(m*n) SC= O(m*n)

// class Solution {
// public:
//     int path(int i, int j, vector<vector<int>>& obstacleGrid,  vector<vector<int>> &dp ){
//         if(i > obstacleGrid.size()-1 || j> obstacleGrid[0].size()-1 ) return 0;
//         if(obstacleGrid[i][j] == 1) return 0;
//         if( i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;
//         if(dp[i][j] != -1) return dp[i][j];
//         dp[i][j]=  path(i+1, j, obstacleGrid, dp) + path(i, j+1, obstacleGrid, dp);
//         return dp[i][j];
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
//         return path(0, 0, obstacleGrid, dp);
//     }
// };

// using tabulation O(m*n) time, O(n) space

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            vector<int> dp(n,0);
            dp[0] = (obstacleGrid[0][0] == 0);

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(obstacleGrid[i][j] == 1){
                        dp[j] = 0;
                    }
                    else if(j>0){
                        dp[j] += dp[j-1];
                    }
                }
            }
            return dp[n-1];

        }
};