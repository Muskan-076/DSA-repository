class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;

        // Collect all obstacles
        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        set<int> s;
        s.insert(0);
        s.insert(MAXX);

        for (int x : obstacles)
            s.insert(x);

        SegmentTree st(MAXX + 1);

        // Build initial gaps
        auto it = s.begin();
        int last = *it;
        ++it;

        while (it != s.end()) {
            int cur = *it;
            st.update(cur, cur - last);
            last = cur;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 2) {

                int x = queries[i][1];
                int sz = queries[i][2];

                auto it = s.upper_bound(x);
                --it;

                int pre = *it;

                int best = st.query(0, pre);
                best = max(best, x - pre);

                ans.push_back(best >= sz);
            }
            else {

                int x = queries[i][1];

                auto it = s.find(x);

                auto leftIt = std::prev(it);
                auto rightIt = std::next(it);

                int left = *leftIt;
                int right = *rightIt;

                s.erase(it);

                st.update(x, 0);
                st.update(right, right - left);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};