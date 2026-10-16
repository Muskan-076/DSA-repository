
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> last(100001, -1);
        long long ans = 0;

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto apply = [&](int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sq[node] = (sq[node] + 2 * val * sum[node]
                        + len * val * val) % MOD;

            sum[node] = (sum[node] + len * val) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        };

        auto push = [&](int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        };

        function<void(int, int, int, int, int)> update =
            [&](int node, int l, int r, int ql, int qr) {
                if (ql > r || qr < l) return;

                if (ql <= l && r <= qr) {
                    apply(node, l, r, 1);
                    return;
                }

                push(node, l, r);

                int mid = (l + r) / 2;
                update(node * 2, l, mid, ql, qr);
                update(node * 2 + 1, mid + 1, r, ql, qr);

                sum[node] = (sum[node * 2] +
                             sum[node * 2 + 1]) % MOD;

                sq[node] = (sq[node * 2] +
                            sq[node * 2 + 1]) % MOD;
            };

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            update(1, 0, n - 1, last[x] + 1, r);

            last[x] = r;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
