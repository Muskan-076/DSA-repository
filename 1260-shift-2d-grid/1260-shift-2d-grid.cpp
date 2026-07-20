class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int total = rows * cols;
        k %= total;

        vector<vector<int>> result(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int currentIndex = i * cols + j;
                int newIndex = (currentIndex + k) % total;

                int newRow = newIndex / cols;
                int newCol = newIndex % cols;

                result[newRow][newCol] = grid[i][j];
            }
        }

        return result;
    }
};