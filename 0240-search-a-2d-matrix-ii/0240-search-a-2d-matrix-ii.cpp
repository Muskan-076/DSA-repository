class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();        // rows
        int m = matrix[0].size();     // columns

        int row = 0;
        int col = m - 1;              // last column

        while(row < n && col >= 0) {

            if(matrix[row][col] == target)
                return true;

            else if(matrix[row][col] > target)
                col--;

            else
                row++;
        }

        return false;
    
        //better solution: tc= o(log m*n) sc= o(1)
        
        // for(int i =0; i< matrix.size(); i++){
        //     int low = 0;
        //     int high = matrix[i].size() -1;
            

        //     while(low< high){
        //         int mid = low + (high-low)/2;

        //         if(matrix[i][mid] < target){
        //             low = mid+1;
        //         }
        //         else if(matrix[i][mid] > target){
        //             high = mid-1;
        //         }
                
        //         else{
        //             return true;
        //         } 
                
                
        //     }

        // }
        // return false;
        
        // brute force solution

        // for(int i =0; i< matrix.size(); i++){
        //     for(int j =0; j< matrix[0].size(); j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};