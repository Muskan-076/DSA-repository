class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //  optimal solution
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstrowzero = false;
        bool firstcolzero = false;

        for(int j =0 ; j<m; j++){
            if(matrix[0][j] == 0){
                firstrowzero = true;
            }
        }
        for(int i =0 ; i<n; i++){
            if(matrix[i][0] == 0){
                firstcolzero = true;
            }
        }

        for(int i =1 ; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
            
        }

        for(int i=1; i< n; i++){
            if(matrix[i][0] == 0) {
                for(int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }

        }
        for(int j = 1; j < m; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

         if(firstrowzero) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if(firstcolzero) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }


        //  Time: O(n × m) Space: O(n + m)

        // int n = matrix.size();
        // int m = matrix[0].size();

        // vector<int> rows(n,0);
        // vector<int> cols(m,0);

        
        // for(int i =0; i< matrix.size(); i++){
        //     for(int j =0; j< matrix[0].size(); j++){
        //         if(matrix[i][j] == 0){
        //             rows[i] = 1;
        //             cols[j] = 1;
        //         }
        //     }
        // }

        // for(int i =0; i< n; i++){
        //     if(rows[i]){
        //         for(int j=0; j< m; j++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        // for(int j =0; j< m; j++){
        //     if(cols[j]){
        //         for(int i=0; i< n; i++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
    }
};