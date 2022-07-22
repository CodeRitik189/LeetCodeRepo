class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), cr = 0, cc = 0;
       
        
       for(int i = 0; i<n; i++)
           if(matrix[0][i]==0)cr = 1;
       for(int i = 0; i<m; i++)
           if(matrix[i][0] == 0)cc = 1;
        
       for(int i = m-1 ; i>=1; i--){
           for(int j = n-1; j>=1; j--){
                if(matrix[i][j] == 0 ){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
       }


        for(int i = m-1 ; i>=1; i--){
            for(int j = n-1; j>=1 ; j--){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(cr){
            for(int i = 0; i<n; i++)matrix[0][i] = 0;
        }
        if(cc){
            for(int i = 0; i<m; i++)matrix[i][0] = 0;
        }
        return;
    }
};


















