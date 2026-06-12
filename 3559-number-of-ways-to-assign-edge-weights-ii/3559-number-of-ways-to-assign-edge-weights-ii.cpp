class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node, adj);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if ((diff >> j) & 1)
                u = up[u][j];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        dfs(1, -1, adj);

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            int d = depth[u] + depth[v] - 2 * depth[w];

            if (d == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[d - 1]);
        }

        return ans;
    }
};