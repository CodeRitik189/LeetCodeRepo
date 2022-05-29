class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    int rec(vector<vector<int>>& v, int i , int m , int n){
        if(i==v.size()){ return 0; }
        
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        if(v[i][0]<=m && v[i][1]<=n ){
            return dp[i][m][n] = max(1+rec(v,i+1,m-v[i][0],n-v[i][1]),rec(v,i+1,m,n));
        }else{
            return dp[i][m][n] = rec(v,i+1,m,n);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
    dp= vector<vector<vector<int>>>(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        vector<vector<int>>v;
        int x = strs.size();
        
        for(int i=0; i<x ; i++){
            int ct = 0, y = strs[i].size();
            for(int j = 0; j<y ; j++){
                if(strs[i][j] == '1'){
                    ct++;
                }
            }
            v.push_back({y-ct,ct});
        }
        
        return rec(v,0,m,n);
    }
};