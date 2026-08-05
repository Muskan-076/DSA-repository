class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find all methods reachable from k
        vector<int> suspicious(n, 0);
        queue<int> q;

        q.push(k);
        suspicious[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        // If a non-suspicious method calls a suspicious method,
        // we cannot remove the suspicious methods.
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                // Nothing can be removed
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};