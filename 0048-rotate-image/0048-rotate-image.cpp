class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // tc= o(n^2) sc=o(1)
        int n = matrix.size();
        for(int i =0; i< matrix.size(); i++){
            for(int j =i+1; j<n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i =0; i< n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};