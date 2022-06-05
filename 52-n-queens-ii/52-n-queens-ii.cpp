class Solution {
public:
     vector<int>br,cr,dr,dl;
     int ans = 0;
    
    void check(vector<string>& mat, int row , int n){
        if(n==0){
            ans++;
            return;
        }
        
        if(row>=mat.size()){
            return;
        }
        
        for(int j=0;j<mat.size();j++){
          if(br[row]||cr[j]||dr[row+j]||dl[mat.size()-1-row+j]){
              continue;
          }
           br[row] = 1;
           cr[j] = 1;
           dl[mat.size()-1-row+j] = 1;
           dr[row+j] = 1;
            
           mat[row][j] = 'Q';
          check(mat, row+1 , n-1);
           mat[row][j] = '.';
           
           br[row] = 0;
           cr[j] = 0;
           dl[mat.size()-1-row+j] = 0;
           dr[row+j] = 0;
        }       
    }
    int totalNQueens(int n) {
         br = vector<int>(n,0);
        cr = vector<int>(n,0);
        dr = vector<int>(2*n,0);
        dl = vector<int>(2*n,0);
        
        vector<string>mat(n,"");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i] += '.';
            }
        }
        check(mat,0,n);
        return ans;
    }
};