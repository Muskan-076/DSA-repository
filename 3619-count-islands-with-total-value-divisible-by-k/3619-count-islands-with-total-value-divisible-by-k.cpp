
class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or water/already visited
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0) {
            return 0;
        }

        // Store current cell value
        long long sum = grid[i][j];

        // Mark as visited
        grid[i][j] = 0;

        // Explore all 4 directions
        sum += dfs(grid, i + 1, j);
        sum += dfs(grid, i - 1, j);
        sum += dfs(grid, i, j + 1);
        sum += dfs(grid, i, j - 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
