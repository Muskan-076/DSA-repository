class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        // Try to make prefix equal to target
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Use same character as target
            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            }
            else {
                // Find smallest character greater than target[i]
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        ans += char('a' + c);
                        cnt[c]--;

                        // Fill remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (cnt[j] > 0) {
                                ans += char('a' + j);
                                cnt[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // Can't continue, so backtrack
                break;
            }
        }

        // Backtrack
        while (!ans.empty()) {
            char last = ans.back();
            ans.pop_back();
            cnt[last - 'a']++;

            int cur = last - 'a';

            // Find smallest character greater than current
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    // Smallest possible suffix
                    for (int j = 0; j < 26; j++) {
                        while (cnt[j] > 0) {
                            ans += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};