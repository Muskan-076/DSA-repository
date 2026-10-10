
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int mx = 0;

        long long k = (long long)k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) total += d;

        if (k >= total) return 0;

        // Binary search for the minimum possible
        // maximum difference.
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) needed += d - mid;
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int x = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > x) {
                used += d - x;
                d = x;
            }

            ans += 1LL * d * d;
        }

        // Distribute leftover operations by reducing
        // some differences equal to x by one.
        long long remaining = k - used;

        ans -= remaining * (2LL * x - 1);

        return ans;
    }
};
