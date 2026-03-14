class Solution {
public:
    vector<string> res;

    void dfs(string &curr, int n) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                dfs(curr, n);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        dfs(curr, n);

        if(k > res.size()) return "";
        return res[k-1];
    }
};
