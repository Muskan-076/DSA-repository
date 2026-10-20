
class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b, int start, int k) {
        // Pattern: corresponding sorted block
        vector<int> pat(b.begin() + start, b.begin() + start + k);

        // Build LPS array
        vector<int> lps(k, 0);
        for (int i = 1, len = 0; i < k;) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search pattern in the original block repeated twice
        int i = 0, j = 0;

        while (i < 2 * k - 1) {
            int x = a[start + i % k];

            if (x == pat[j]) {
                i++;
                j++;

                if (j == k) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
