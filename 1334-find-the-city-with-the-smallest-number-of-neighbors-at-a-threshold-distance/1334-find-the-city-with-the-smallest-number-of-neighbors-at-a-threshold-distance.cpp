class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // vector<vector<int>> adj[n];
        // for(auto it : edges){
        //     adj[it[0]].push_back({it[1], it[2]});
        //     adj[it[1]].push_back({it[0], it[2]});
        // }

        // priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> >pq;
        // vector<int> dist(n, 1e9)

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for(int i =0; i< n; i++){
            dist[i][i] = 0;
        }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k = 0; k < n; k++){
            for(int i =0; i < n; i++){
                for(int j =0; j< n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int minCount = INF;

        for(int i =0; i<n; i++){
            int count = 0;

            for(int j =0; j<n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= minCount){
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};