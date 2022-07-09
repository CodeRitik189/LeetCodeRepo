class Solution {
public:
    bool check(vector<vector<int>>& v, int st, vector<int>& vis){
        vis[st] = 1;
        for(auto &x : v[st]){
            if(vis[x]==1)return false;
            else if(vis[x]==0 && !check(v,x,vis))return false;
        }
        vis[st] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>v(n);
        for(int i = 0  ; i<pre.size(); i++){
            v[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>vis(n,0);
        
        for(int i = 0 ; i<n; i++){
          if(vis[i]==0 && !check(v,i,vis))return false;
        }
        return true;
    }
};