// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
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
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
    check(matrix,0,0,r-1,c-1);
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends