class Solution {
public:
    vector<int>ans;
    void check(vector<vector<int>>& mat, int x, int y,int a,int b){
        if(x>a || y>b ){
            return;
        }
        for(int i=y;i<=b;i++){
           ans.push_back(mat[x][i]); 
        }
        for(int i=x+1;i<=a;i++){
           ans.push_back(mat[i][b]); 
        }
        for(int i=b-1;i>=y;i--){
           if(a!=x)
           ans.push_back(mat[a][i]); 
        }
        for(int i=a-1;i>x;i--){
           if(b!=y)
           ans.push_back(mat[i][y]); 
        }
        check(mat,x+1,y+1,a-1,b-1);
        return;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        check(matrix,0,0,m-1,n-1);
        return ans;
    }
};