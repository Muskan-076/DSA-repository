class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        //optimal soln:

        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find maximum element in column mid
            int row = 0;

            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[row][mid]) {
                    row = i;
                }
            }

            // Left and right neighbors
            int left = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

            // Peak found
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }

            // Move towards larger neighbor
            if (left > mat[row][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
        // tc = o(n*m) sc =o(1)

        // int n = mat.size();
        // int m = mat[0].size();
        // vector<int> ans;
        // for(int i = 0; i< n; i++){
        //     for(int j = 0; j< m; j++){

        //         int up = (i > 0) ? mat[i-1][j] : -1;
        //         int down = (i < n-1) ? mat[i+1][j] : -1;
        //         int left = (j> 0) ? mat[i][j-1] : -1;
        //         int right = (j < m-1) ? mat[i][j+1] : -1;
        //         if(mat[i][j] > up && 
        //             mat[i][j] >  left &&
        //             mat[i][j] > down &&
        //             mat[i][j] > right){
                        
        //                 return { i, j};
        //             }
        //     }   
        // }
        // return {};
    }
};