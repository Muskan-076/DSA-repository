class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char ch : s) cnt[ch - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++)
            if (cnt[c] % 2) { oddCount++; oddChar = c; }

        bool isOdd = (n % 2 == 1);
        if ((isOdd && oddCount != 1) || (!isOdd && oddCount != 0)) return "";

        int h = n / 2;
        int M[26];
        for (int c = 0; c < 26; c++) M[c] = cnt[c] / 2;
        char mid = isOdd ? char('a' + oddChar) : 0;

        // cntT[i][c] = count of c in target[0..i-1]
        vector<array<int,26>> cntT(h + 1);
        cntT[0].fill(0);
        for (int i = 0; i < h; i++) {
            cntT[i + 1] = cntT[i];
            cntT[i + 1][target[i] - 'a']++;
        }

        // --- Case B: F == target[0:h] exactly ---
        bool caseB = true;
        for (int c = 0; c < 26; c++)
            if (cntT[h][c] != M[c]) { caseB = false; break; }

        if (caseB) {
            string T1 = target.substr(0, h);
            string rev = T1;
            reverse(rev.begin(), rev.end());
            string suffixCand = (isOdd ? string(1, mid) : "") + rev;
            string targetSuffix = target.substr(h);
            if (suffixCand > targetSuffix) return T1 + suffixCand;
        }

        // --- Case A: smallest F strictly greater than target[0:h] ---
        for (int i = h - 1; i >= 0; i--) {
            bool achievable = true;
            for (int c = 0; c < 26; c++)
                if (cntT[i][c] > M[c]) { achievable = false; break; }
            if (!achievable) continue;

            int rem[26];
            for (int c = 0; c < 26; c++) rem[c] = M[c] - cntT[i][c];

            int tc = target[i] - 'a', chosen = -1;
            for (int c = tc + 1; c < 26; c++)
                if (rem[c] > 0) { chosen = c; break; }
            if (chosen == -1) continue;

            rem[chosen]--;
            string F = target.substr(0, i);
            F += char('a' + chosen);
            for (int c = 0; c < 26; c++) F += string(rem[c], char('a' + c));

            string rev = F;
            reverse(rev.begin(), rev.end());
            return F + (isOdd ? string(1, mid) : "") + rev;
        }

        return "";
    }
};