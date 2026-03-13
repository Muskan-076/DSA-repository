class Solution {
public:
    long long maxHeight(long long t, vector<int>& workerTimes) {
        long long total = 0;

        for (long long wt : workerTimes) {
            long long val = (2 * t) / wt;
            long long x = sqrt(val);

            while ((wt * x * (x + 1)) / 2 > t) x--;
            while ((wt * (x + 1) * (x + 2)) / 2 <= t) x++;

            total += x;
        }

        return total;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e18;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (maxHeight(mid, workerTimes) >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
