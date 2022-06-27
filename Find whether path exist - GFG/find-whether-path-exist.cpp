// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool check(vector<vector<int>>& grid, int r, int c,vector<vector<int>>& vis){
        if(r<0||c<0||r>=grid.size()||c>=grid.size()||vis[r][c]==1||grid[r][c]==0){
            return false;
        }
        if(grid[r][c] == 2){ return true; }
        vis[r][c] = true;
        
        bool ans = false;
        
        ans |= check(grid,r,c-1,vis);
        ans |= check(grid,r-1,c,vis);
        ans |= check(grid,r,c+1,vis);
        ans |= check(grid,r+1,c,vis);
        
        vis[r][c] = false;
        return ans;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 ){
                    return check(grid,i,j,vis);
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends