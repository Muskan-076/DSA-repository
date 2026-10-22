
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        auto getShift = [&](vector<int>& a) -> int {
            int k = 0;

            while (k < n && a[k] != 0) {
                k++;
            }

            for (int j = 0; j < n; j++) {
                if (a[(k + j) % n] != j) {
                    return -1;
                }
            }

            return k;
        };

        int ans = INT_MAX;

        // Case 1: Only rotations are needed.
        int k = getShift(nums);

        if (k != -1) {
            ans = min(k, n - k + 2);
        }

        // Case 2: Reverse once, then rotate.
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        k = getShift(rev);

        if (k != -1) {
            ans = min(ans, 1 + min(k, n - k));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
