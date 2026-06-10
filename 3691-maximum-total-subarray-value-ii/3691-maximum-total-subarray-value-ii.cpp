class Solution {
public:
    using ll = long long;

    vector<vector<int>> mx, mn;
    vector<int> lg;

    int getMax(int l, int r) {
        int k = lg[r - l + 1];
        return max(mx[k][l], mx[k][r - (1 << k) + 1]);
    }

    int getMin(int l, int r) {
        int k = lg[r - l + 1];
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    }

    long long value(int l, int r) {
        return 1LL * getMax(l, r) - getMin(l, r);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int LOG = lg[n] + 1;

        mx.assign(LOG, vector<int>(n));
        mn.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = mn[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (1 << (j - 1))]);

                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (1 << (j - 1))]);
            }
        }

        struct Node {
            long long val;
            int l, r;

            bool operator<(const Node& other) const {
                return val < other.val; // max heap
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r - 1 >= l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};