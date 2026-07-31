class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if( cables < n-1 ){
            return -1;
        }

        vector<vector<int>> adj(n);

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n , 0);

        int components = 0;

        for(int i =0 ; i< n; i++){
            if(vis[i] == 1){
                continue;
            }

            components++;

            queue<int> q;
            q.push(i);
            vis[i] =1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neighbour : adj[node]){
                    if(!vis[neighbour]){
                        vis[neighbour] = 1;
                        q.push(neighbour);
                    }
                }
            }
        }
        return components - 1;
    }
};