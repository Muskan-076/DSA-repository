class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            farthest = max(farthest, i + nums[i]);

            if(i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

// recursively
// class Solution {
// public:

//     int solve(int i, vector<int>& nums) {

//     int n = nums.size();

//         // Reached last index
//         if(i == n-1)
//             return 0;

//         int mini = INT_MAX;

//         // Try every possible jump
//         for(int jump = 1; jump <= nums[i]; jump++) {

//             if(i + jump < n) {

//                 mini = min(mini,
//                            1 + solve(i + jump, nums));
//             }
//         }

//         return mini;
//     }

//     int jump(vector<int>& nums) {

//         return solve(0, nums);

//     }
// };



// using dp
// class Solution {
// public:

//     int solve(int i, vector<int>& nums, vector<int>& dp) {

//         int n = nums.size();

//         if(i == n-1)
//             return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         int mini = INT_MAX;

//         for(int jump = 1; jump <= nums[i]; jump++) {

//             if(i + jump < n) {

//                 mini = min(mini, 1 + solve(i + jump, nums, dp));
//             }
//         }

//         return dp[i] = mini;
//     }

//     int jump(vector<int>& nums) {

//         int n = nums.size();

//         vector<int> dp(n,-1);

//         return solve(0, nums, dp);

//     }
// };


