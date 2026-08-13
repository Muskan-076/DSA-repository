class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen;
        int best;
        int len;

        Node() {
            leftChar = rightChar = '#';
            leftLen = rightLen = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.leftLen = a.leftLen;

        if (a.leftLen == a.len && a.rightChar == b.leftChar) {
            res.leftLen = a.len + b.leftLen;
        }

        // Suffix
        res.rightLen = b.rightLen;

        if (b.rightLen == b.len && a.rightChar == b.leftChar) {
            res.rightLen = b.len + a.rightLen;
        }

        // Best inside either half
        res.best = max(a.best, b.best);

        // Best crossing the middle
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.rightLen + b.leftLen);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {

            tree[idx].leftChar = s[l];
            tree[idx].rightChar = s[l];

            tree[idx].leftLen = 1;
            tree[idx].rightLen = 1;

            tree[idx].best = 1;
            tree[idx].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {

            tree[idx].leftChar = ch;
            tree[idx].rightChar = ch;

            tree[idx].leftLen = 1;
            tree[idx].rightLen = 1;

            tree[idx].best = 1;
            tree[idx].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        }
        else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
    
        // tc= O(n × q)
    //     vector<int> ans;
    //     for(int i =0; i<queryIndices.size(); i++){
    //         s[queryIndices[i]]= queryCharacters[i];

    //         int high = 1;
    //         int curr =1;


    //         for(int j =1; j< s.size(); j++){

    //             if(s[j] == s[j-1]) curr++;

    //             else{
    //                 curr =1;
    //             }
    //             high = max(high, curr);
                
    //         }
    //         ans.push_back(high);
    //     }
    //     return ans;
    // }
