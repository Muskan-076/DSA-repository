class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxLen = 1;
        int r = 0;

        for (int l = 0; l < n; l++) {
            while (r < n && (long long)nums[r] <= (long long)nums[l] * k) {
                r++;
            }
            maxLen = max(maxLen, r - l);
        }

        return n - maxLen;
    }
};
