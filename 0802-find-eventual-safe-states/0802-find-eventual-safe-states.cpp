class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        
        vector<vector<int>> adjRev(v);
        vector<int> indegree(v, 0);

        for(int i = 0; i < v; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};