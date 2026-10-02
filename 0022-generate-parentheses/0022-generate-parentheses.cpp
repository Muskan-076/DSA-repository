class Solution {
public:
    void generate(string curr, int open, int close, int n,
                  vector<string>& ans) {

        // We have used all brackets
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add an opening bracket
        if (open < n) {
            generate(curr + "(", open + 1, close, n, ans);
        }

        // Add a closing bracket only if it is safe
        if (close < open) {
            generate(curr + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate("", 0, 0, n, ans);

        return ans;
    }
};