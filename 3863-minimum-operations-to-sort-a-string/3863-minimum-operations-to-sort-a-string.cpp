class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) return 1;

        int cntMn = count(s.begin(), s.end(), mn);
        int cntMx = count(s.begin(), s.end(), mx);

        // max is unique and at the front, min is unique and at the back
        if (s[0] == mx && cntMx == 1 && s[n - 1] == mn && cntMn == 1) return 3;

        return 2;
    }
};