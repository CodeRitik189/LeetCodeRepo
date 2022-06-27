// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>>dist;
    void insert(queue<pair<int,int>>& qp,vector<vector<int>>& grid, pair<int,int>& p ){
        int i = p.first, j = p.second;
        grid[i][j] = 2;
        if(i>0){
            dist[i-1][j] = min(dist[i-1][j],1+dist[i][j]);
            qp.push({i-1,j}); 
        }
        if(i<grid.size()-1 ){
             dist[i+1][j] = min(dist[i+1][j],1+dist[i][j]);
             qp.push({i+1,j}); 
        }
        if(j>0){
            dist[i][j-1] = min(dist[i][j-1],1+dist[i][j]);
            qp.push({i,j-1}); 
        }
        if(j<grid[0].size()-1){
            dist[i][j+1] = min(dist[i][j+1],1+dist[i][j]);
            qp.push({i,j+1}); 
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    dist = vector<vector<int>>(n,vector<int>(m,n*m));
	    
	    int ct = 0 , crt = 0;
        queue<pair<int,int>>qp;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dist[i][j] = 0;
                    qp.push({i,j});
                }
            }
        }
        
        while(!qp.empty()){
              pair<int,int>p = qp.front();
              qp.pop();
              if(grid[p.first][p.second]!=2)
               insert(qp,grid,p);
        }
        
        return dist;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends