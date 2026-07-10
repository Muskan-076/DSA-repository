//Time: O(m × n) Space: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};

// using memoization Time: O(m × n) Space: O(m × n)

// class Solution {
// public:
//     int path(int first, int second , int m, int n, vector<vector<int>> &dp){
       
//             if(first == m-1 && second == n-1) return 1;
//             if (first > m-1 || second > n-1) return 0;

//             if(dp[first][second] != -1) return dp[first][second];

//             dp[first][second] = path(first+1, second, m , n, dp) + path(first, second+1, m, n, dp);

//             return dp[first][second];
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n, -1));
//        return path(0,0, m ,n, dp);
//     }
// };


// // tabulation Time: O(m × n) Space: O(m × n)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for(int i = 0; i < m; i++)
//             dp[i][0] = 1;

//         for(int j = 0; j < n; j++)
//             dp[0][j] = 1;

//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };


