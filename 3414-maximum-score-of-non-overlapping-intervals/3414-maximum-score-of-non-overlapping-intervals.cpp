class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        // dp[i][k] = best answer starting from i
        // when we can still choose k intervals.
        //
        // Each state stores:
        // {maximum weight, chosen indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Find first interval whose start > current right endpoint
        auto getNext = [&](long long right) {
            int lo = 0, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > right)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            return lo;
        };

        // Compare two candidate answers
        auto better = [&](pair<long long, vector<int>> x,
                          pair<long long, vector<int>> y) {

            // Higher weight is better
            if (x.first != y.first)
                return x.first > y.first;

            // Same weight -> lexicographically smaller indices
            return x.second < y.second;
        };

        // Base case: no intervals left
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take interval i
                auto best = dp[i + 1][k];

                // Option 2: take interval i
                int nxt = getNext(a[i][1]);

                auto take = dp[nxt][k - 1];

                take.first += a[i][2];
                take.second.push_back((int)a[i][3]);

                // We need indices in sorted order for
                // lexicographical comparison.
                sort(take.second.begin(), take.second.end());

                if (better(take, best))
                    best = take;

                dp[i][k] = best;
            }
        }

        return dp[0][4].second;
    }
};