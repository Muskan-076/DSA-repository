
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // candidates: (end, start) pairs, sorted by end for greedy selection
        vector<pair<int,int>> candidates;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue; // only try starts at first occurrence

            int start = i, end = last[c];
            bool valid = true;

            for (int j = start; j <= end; j++) {
                int c2 = s[j] - 'a';
                if (first[c2] < start) {
                    valid = false;
                    break;
                }
                if (last[c2] > end) {
                    end = last[c2]; // extend window
                }
            }

            if (valid) {
                candidates.push_back({end, start});
            }
        }

        sort(candidates.begin(), candidates.end()); // sort by end (then start)

        vector<string> result;
        int lastEnd = -1;
        for (auto& [end, start] : candidates) {
            if (start > lastEnd) {
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }

        return result;
    }
};