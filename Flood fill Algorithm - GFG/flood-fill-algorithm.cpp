// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

   void check(vector<vector<int>>& grid, int r, int c,vector<vector<int>>& vis,int& nc){
        vis[r][c] = true;
    
        if(c>0 && !vis[r][c-1] && grid[r][c] == grid[r][c-1])check(grid,r,c-1,vis,nc);
        if(r>0 && !vis[r-1][c] && grid[r][c] == grid[r-1][c])check(grid,r-1,c,vis,nc);
        if(c<grid[0].size()-1 && !vis[r][c+1] && grid[r][c] == grid[r][c+1])check(grid,r,c+1,vis,nc);
        if(r<grid.size()-1 && !vis[r+1][c] && grid[r][c] == grid[r+1][c])check(grid,r+1,c,vis,nc);
        
        grid[r][c] = nc;
        vis[r][c] = false;
        return ;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size(), m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        check(image,sr, sc,vis, newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends