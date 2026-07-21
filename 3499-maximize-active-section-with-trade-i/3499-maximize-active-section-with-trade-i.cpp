
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count the number of existing 1s.
        int ones = count(s.begin(), s.end(), '1');

        // Add the required virtual 1s at both ends.
        string t = "1" + s + "1";

        int best = 0;

        // Run-length encode the augmented string.
        vector<pair<char, int>> runs;

        for (int i = 0; i < t.size(); ) {
            int j = i;

            while (j < t.size() && t[j] == t[i]) {
                j++;
            }

            runs.push_back({t[i], j - i});
            i = j;
        }

        // Look for:
        // 0-block | 1-block | 0-block
        //
        // We remove the 1-block and turn the merged 0-block into 1s.
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int leftZeros = runs[i - 1].second;
                int rightZeros = runs[i + 1].second;

                best = max(best, leftZeros + rightZeros);
            }
        }

        return ones + best;
    }
};

