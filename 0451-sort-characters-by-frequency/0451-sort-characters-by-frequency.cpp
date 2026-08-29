class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        // Store characters
        vector<pair<char, int>> v;

        for (auto it : freq) {
            v.push_back({it.first, it.second});
        }

        // Sort by frequency decreasing
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build answer
        string ans;

        for (auto it : v) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};