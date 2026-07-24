class Solution {
public:

    void fwht(vector<long long>& a, bool inverse) {
        int n = a.size();

        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    long long u = a[i + j];
                    long long v = a[i + j + len];

                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                }
            }
        }

        if (inverse) {
            for (long long &x : a) {
                x /= n;
            }
        }
    }

    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;

        vector<long long> a(M, 0);

        // Presence of each value
        for (int x : nums) {
            a[x] = 1;
        }

        // XOR transform
        fwht(a, false);

        // Three XOR convolution:
        // A XOR A XOR A
        for (long long &x : a) {
            x = x * x * x;
        }

        // Inverse transform
        fwht(a, true);

        int ans = 0;

        for (int x = 0; x < M; x++) {
            if (a[x] > 0) {
                ans++;
            }
        }

        return ans;
    }
};