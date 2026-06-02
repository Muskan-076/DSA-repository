class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;

        // Frequency of characters in t
        for (char c : t)
            need[c]++;

        int required = need.size(); // unique chars needed
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            // Character frequency matched
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try shrinking window
            while (left <= right && formed == required) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                // Window becomes invalid
                if (need.count(ch) && window[ch] < need[ch])
                    formed--;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};