
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> right(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> down(m + 1, vector<long long>(n + 1, 0));

        // Destination
        right[m - 1][n - 1] = 1;
        down[m - 1][n - 1] = 1;

        // Bottom-up DP
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                if (grid[i][j] == 1) {
                    // Mirror: entered from left
                    right[i][j] = down[i + 1][j];

                    // Mirror: entered from above
                    down[i][j] = right[i][j + 1];
                }
                else {
                    // Empty cell: choose right or down
                    long long ways = (
                        right[i][j + 1] +
                        down[i + 1][j]
                    ) % MOD;

                    right[i][j] = ways;
                    down[i][j] = ways;
                }
            }
        }

        return down[0][0] % MOD;
    }
};
