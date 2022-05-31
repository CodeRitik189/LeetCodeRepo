class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int l = INT_MAX,r = INT_MAX, u = INT_MAX;
                
                if(j>0){l = matrix[i-1][j-1]; }
                if(j<m-1){ r = matrix[i-1][j+1];}
                u = matrix[i-1][j];
                
                matrix[i][j] += min(u,min(r,l));
            }
        }
        
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            mn = min(mn,matrix[m-1][i]);
        }
        return mn;
    }
};