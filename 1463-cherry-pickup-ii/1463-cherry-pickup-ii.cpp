class Solution {
public:
    vector<vector<vector<int>>>dp;
    int check(vector<vector<int>>& grid, int r, int c1, int c2){
        if(c1<0 || c1>=grid[0].size() || c2<0 || c2>=grid[0].size()){
            return 0;
        }
        if(r == grid.size()){return 0;}
        
        if(dp[r][c1][c2]!=-1){ return dp[r][c1][c2]; }
        
        int ans = 0;
        for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
            if(c1==c2)
              ans = max(ans,check(grid,r+1,c1+i,c2+j)+grid[r][c1]);
            else
              ans = max(ans,check(grid,r+1,c1+i,c2+j)+grid[r][c1]+grid[r][c2]);
          }
        }
        return dp[r][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return check(grid,0,0,n-1);
    }
};