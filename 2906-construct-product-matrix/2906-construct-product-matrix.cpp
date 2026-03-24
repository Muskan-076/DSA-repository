class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;
        const int MOD = 12345;

        vector<long long> arr(size);

        // Flatten grid
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[idx++] = grid[i][j] % MOD;
            }
        }

        vector<long long> prefix(size, 1), suffix(size, 1);

        // Prefix product
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }

        // Suffix product
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        // Build result
        vector<vector<int>> result(n, vector<int>(m));
        idx = 0;
        for (int i = 0; i < size; i++) {
            long long val = (prefix[i] * suffix[i]) % MOD;
            result[i / m][i % m] = val;
        }

        return result;
    }
};