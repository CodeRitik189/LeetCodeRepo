// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(vector<vector<char>>& grid,int m, int n, vector<vector<int>>& vis ){
        if(m<0||n<0 || m>= grid.size()||n>= grid[0].size()||grid[m][n]=='0'|| vis[m][n]){
            return ;
        }
        vis[m][n] = true;
        
        for(int i = -1; i<= 1; i++){
            for(int j = -1; j<= 1; j++){
                bfs(grid,m+i,n+j,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size(), ct = 0;
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i = 0; i< m ; i++){
            for(int j = 0 ; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j] ){
                    bfs(grid,i,j,vis);
                    ct++;
                }
            }
        }
        return ct;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends