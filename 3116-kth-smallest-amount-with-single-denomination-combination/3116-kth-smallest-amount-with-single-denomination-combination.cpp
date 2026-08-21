class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto check = [&](long long x) {
            long long cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long cur = 1;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        cur = lcm(cur, (long long)coins[i]);
                        if (cur > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;

                if (__builtin_popcount(mask) & 1)
                    cnt += x / cur;
                else
                    cnt -= x / cur;
            }

            return cnt >= k;
        };

        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};