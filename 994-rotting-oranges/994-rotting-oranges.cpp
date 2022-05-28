class Solution {
public:
    void insert(queue<pair<int,int>>& qp,vector<vector<int>>& grid, pair<int,int>& p ){
        int i = p.first, j = p.second;
        
        if(i>0 && grid[i-1][j] == 1){
            grid[i-1][j] = 2;
            qp.push({i-1,j}); 
        }
        if(i<grid.size()-1 && grid[i+1][j] == 1){
             grid[i+1][j] = 2;
            qp.push({i+1,j}); 
        }
        if(j>0 && grid[i][j-1] == 1){
             grid[i][j-1] = 2;
            qp.push({i,j-1}); 
        }
        if(j<grid[0].size()-1 && grid[i][j+1] == 1){
             grid[i][j+1] = 2;
            qp.push({i,j+1}); 
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ct = 0 , crt = 0;
        queue<pair<int,int>>qp;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    qp.push({i,j});
                }
                if(grid[i][j]!=0){crt++;}
            }
        }
        
        while(!qp.empty()){
           int k = qp.size();
           crt -= k;
           while(k--){
              pair<int,int>p = qp.front();
              qp.pop();
              insert(qp,grid,p);
           }
            ct++;
        }
        
        return crt==0?max(0,ct-1):-1;
    }
};