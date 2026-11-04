
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        // Maintain left half with the median included.
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }

            // Balance the two halves.
            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumL
                 + sumR - median * (long long)right.size();
        };

        vector<long long> cost(n - x + 1);

        // Calculate cost of every window.
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // DP: previous and current rows.
        const long long INF = 4e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Don't select a window ending here.
                curr[i] = curr[i - 1];

                // Select window [i-x, i-1].
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};
