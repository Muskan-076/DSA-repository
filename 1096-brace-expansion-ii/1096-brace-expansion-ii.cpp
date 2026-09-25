class Solution {
public:
    string s;
    int pos = 0;

    set<string> parse() {
        set<string> result;
        set<string> current = {""};

        while (pos < s.size() && s[pos] != '}') {

            if (s[pos] == ',') {
                // Union current result into final result
                result.insert(current.begin(), current.end());

                current.clear();
                current.insert("");

                pos++;
            }
            else {
                set<string> next;

                if (s[pos] == '{') {
                    pos++;  // skip '{'
                    next = parse();
                    pos++;  // skip '}'
                }
                else {
                    next.insert(string(1, s[pos]));
                    pos++;
                }

                // Concatenate current × next
                set<string> temp;

                for (string a : current) {
                    for (string b : next) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        // Add the last expression
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};