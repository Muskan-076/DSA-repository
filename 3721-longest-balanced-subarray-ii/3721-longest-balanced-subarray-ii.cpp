// leetcode 3721
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Maximum possible distinct count is limited
        int maxDistinct = sqrt(n) + 2;

        for (int target = 1; target <= maxDistinct; target++) {

            unordered_map<int,int> evenFreq;
            unordered_map<int,int> oddFreq;

            int left = 0;
            int distinctEven = 0, distinctOdd = 0;

            for (int right = 0; right < n; right++) {

                if (nums[right] % 2 == 0) {
                    if (++evenFreq[nums[right]] == 1)
                        distinctEven++;
                } else {
                    if (++oddFreq[nums[right]] == 1)
                        distinctOdd++;
                }

                // shrink window if distinct exceeds target
                while (distinctEven > target || distinctOdd > target) {

                    if (nums[left] % 2 == 0) {
                        if (--evenFreq[nums[left]] == 0)
                            distinctEven--;
                    } else {
                        if (--oddFreq[nums[left]] == 0)
                            distinctOdd--;
                    }
                    left++;
                }

                if (distinctEven == target && distinctOdd == target) {
                    ans = max(ans, right - left + 1);
                }
            }
        }

        return ans;

    }
};

