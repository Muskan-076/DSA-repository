class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                set<int> st;
                
                // Collect unique elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }
                
                // Convert to vector
                vector<int> vals(st.begin(), st.end());
                
                // If only one distinct element
                if (vals.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }
                
                int minDiff = INT_MAX;
                
                for (int t = 1; t < vals.size(); t++) {
                    minDiff = min(minDiff, vals[t] - vals[t - 1]);
                }
                
                ans[i][j] = minDiff;
            }
        }
        
        return ans;
    }
};