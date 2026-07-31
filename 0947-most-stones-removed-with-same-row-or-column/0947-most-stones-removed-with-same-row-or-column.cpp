class DSU {
public:

    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};


class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {

        int OFFSET = 10001;

        DSU dsu(20002);

        unordered_set<int> nodes;

        for (auto &stone : stones) {

            int row = stone[0];
            int col = stone[1] + OFFSET;

            dsu.unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (int node : nodes) {

            if (dsu.find(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};