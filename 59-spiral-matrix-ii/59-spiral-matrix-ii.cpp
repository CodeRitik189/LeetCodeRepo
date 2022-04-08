class Solution {
public:
    int val = 1;
    void check(vector<vector<int>>& mat, int x,int a){
        if(x>a){
            return;
        }
        for(int i=x;i<=a;i++){
           mat[x][i] = val;
           val++;
        }
        for(int i=x+1;i<=a;i++){
           mat[i][a] = val;
           val++; 
        }
        for(int i=a-1;i>=x;i--){
           if(a!=x){
            mat[a][i] = val;
            val++;
           }
        }
        for(int i=a-1;i>x;i--){
           if(a!=x){
             mat[i][x] = val;
             val++;
           } 
        }
        check(mat,x+1,a-1);
        return;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        check(matrix,0,n-1);
        return matrix;
    }
};