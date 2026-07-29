class Solution {
public:
    static const long long CAP = 2000000; // strictly greater than max possible k (1e6)

    // Compute C(n, r) but stop early once it exceeds CAP (returns CAP+1 as a sentinel)
    long long nCr_capped(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        long long result = 1;
        for (int i = 1; i <= r; i++) {
            long long m = n - r + i;
            result = result * m / i; // exact due to binomial recurrence
            if (result > CAP) return CAP + 1;
        }
        return result;
    }

    // Number of distinct permutations of the multiset described by counts[],
    // using exactly `total` items in total. Capped at CAP.
    long long multinomialCapped(int total, std::array<int,26>& counts) {
        long long result = 1;
        int remaining = total;
        for (int c = 0; c < 26; c++) {
            int ci = counts[c];
            if (ci == 0) continue;
            long long part = nCr_capped(remaining, ci);
            result *= part;
            if (result > CAP) return CAP + 1;
            remaining -= ci;
        }
        return result;
    }

    string smallestPalindrome(string s, int kk) {
        long long k = kk;
        int n = s.size();

        std::array<int,26> cnt{};
        for (char ch : s) cnt[ch - 'a']++;

        std::array<int,26> halfCnt{};
        char middle = 0;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2 == 1) middle = 'a' + c;
            halfCnt[c] = cnt[c] / 2;
        }

        int halfLen = n / 2;

        long long total = multinomialCapped(halfLen, halfCnt);
        if (k > total) return "";

        string half;
        half.reserve(halfLen);
        int remaining = halfLen;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) continue;
                halfCnt[c]--; // tentatively use this character
                long long trial = multinomialCapped(remaining - 1, halfCnt);
                if (k <= trial) {
                    half.push_back('a' + c);
                    remaining--;
                    break;
                } else {
                    k -= trial;
                    halfCnt[c]++; // undo, try next character
                }
            }
        }

        string res = half;
        if (middle != 0) res.push_back(middle);
        string rev = half;
        std::reverse(rev.begin(), rev.end());
        res += rev;
        return res;
    }
};