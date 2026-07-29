class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Starting or ending cell is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        vector<vector<int>> length(n, vector<int>(n, 1e9));

        length[0][0] = 1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});

        // 8 possible directions
        int dr[] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int dc[] = {0, 1, 0, -1, -1, 1, 1, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int len = it.second;

            // Destination reached
            if (r == n - 1 && c == n - 1) {
                return len;
            }

            for (int i = 0; i < 8; i++) {

                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < n &&
                    grid[newr][newc] == 0 &&
                    length[newr][newc] == 1e9) {

                    length[newr][newc] = len + 1;

                    q.push({{newr, newc}, len + 1});
                }
            }
        }

        return -1;
    }
};