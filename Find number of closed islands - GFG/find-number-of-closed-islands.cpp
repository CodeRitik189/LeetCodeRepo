// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    void dfs(vector<vector<int>>& mat,int i, int j){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]!=1){
            return;
        }
        mat[i][j] = 2;
        dfs(mat,i+1,j);
        dfs(mat,i-1,j);
        dfs(mat,i,j+1);
        dfs(mat,i,j-1);
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        
        for(int i = 0; i<n ; i++){
            if(mat[i][0]==1){
                dfs(mat,i,0);
            }
            if(mat[i][m-1]==1){
                dfs(mat,i,m-1);
            }
        }
        for(int i = 0; i<m ; i++){
            if(mat[0][i]==1){
                dfs(mat,0,i);
            }
            if(mat[n-1][i]==1){
                dfs(mat,n-1,i);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==1){
                    ans++;
                    dfs(mat,i,j);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}

  // } Driver Code Ends