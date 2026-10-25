
class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        // If we go outside the grid, this path cannot form a closed island
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        // Water or an already visited cell
        if (grid[i][j] == 1)
            return true;

        // Mark this land cell as visited
        grid[i][j] = 1;

        // Explore all four directions
        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
