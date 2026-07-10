// space optimal solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

// memoization 
// class Solution {
// public:
//     bool solve(int index, int target,
//                vector<int>& nums,
//                vector<vector<int>>& dp) {

//         if (target == 0)
//             return true;

//         if (index == nums.size() || target < 0)
//             return false;

//         if (dp[index][target] != -1)
//             return dp[index][target];

//         bool take = solve(index + 1, target - nums[index], nums, dp);
//         bool skip = solve(index + 1, target, nums, dp);

//         return dp[index][target] = take || skip;
//     }

//     bool canPartition(vector<int>& nums) {

//         int sum = 0;

//         for (int x : nums)
//             sum += x;

//         if (sum % 2 != 0)
//             return false;

//         int target = sum / 2;

//         vector<vector<int>> dp(nums.size(),
//                                vector<int>(target + 1, -1));

//         return solve(0, target, nums, dp);
//     }
// };