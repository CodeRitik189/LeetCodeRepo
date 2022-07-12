class Solution {
public:
    void dfs(vector<vector<int>>& iC, vector<int>& vis, int st){
        vis[st] = true;
        for(int i = 0; i<iC.size(); i++){
            if(st != i && iC[st][i] ==1 && !vis[i])
             dfs(iC,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& iC) {
        int n = iC.size();
        vector<int>vis(n,0);
        
        int ans = 0;
        for(int i =0 ; i<n; i++){
            if(!vis[i]){
              dfs(iC,vis,i);
              ans++;
            }
        }
        return ans;
    }
};