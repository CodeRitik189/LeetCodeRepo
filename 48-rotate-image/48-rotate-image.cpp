class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>>mat(n,vector<int>(n));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                mat[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = mat;
    }
};