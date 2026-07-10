// space optimized DP since we only need two vlaues, so instead of computing dp[i], we only need the previous two values.
class Solution{
public:
    int climbStairs(int n) {
        if(n <= 1){
            return 1;
        }
        int prev2 = 1;
        int prev1 = 1;

        for(int i =2; i<= n; i++){
            int curr = prev2 + prev1 ;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }  
};

//  TC = O(2^N)
// class Solution {
// public:
//     void numberofways(int start,int &n, int &cnt){
//         if(start == n) {
//             cnt++;
//             return;
//         }

//         if(start > n) return;

//         numberofways(start+1, n , cnt);
//         numberofways(start+2, n , cnt);
//     }

//     int climbStairs(int n) {
//         int cnt = 0;
//         numberofways(0, n, cnt);
//         return cnt;
        
//     }
// };


// TC = O(2^n) SC= O(n) better way to right recursive code instead of initializing global count
// class Solution{
// public:
//     int solve(int start, int n){
//         if(start == n) return 1;
//         if(start >n ) return 0;

//         return solve(start+1, n)+ solve(start+2, n);
//     }
//     int climbStairs(int n){
//         return solve(0,n);
//     }
// };


// using memoization  TC=O(n) SC=O(n)

// class Solution{
// public:
//     int solve(int start, int n, int &vis){
//         vis[start] = 1;
//         if(start == n) return 1;
//         if(start > n) return 0;

//         if(dp[start] != -1)
//             return dp[start];

//         dp[start] = solve(start+1, n, dp) + solve(start+2, n ,dp);
        
//         return dp[start];
        

//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1 ,-1);
//         return solve(0, n , vis);
//     }
// };


// tabulation (Bottom-up DP) TC=O(N), SC= o(n)
// class Solution{
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1);

//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i =2; i<=n; i++){
//             dp[i] = dp[i-1] + dp[i+2];
//         }

//         return dp[n];
//     }
// };


