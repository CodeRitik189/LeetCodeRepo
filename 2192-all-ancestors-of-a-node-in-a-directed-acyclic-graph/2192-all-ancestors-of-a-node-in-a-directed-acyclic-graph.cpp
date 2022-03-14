class Solution {
public:
    //brute force easy to understand solution
    void check(vector<vector<int>>& vm,vector<int>& vis,int sv){
        if(vis[sv]){return;}
        vis[sv]=true;
        for(int i=0;i<vm[sv].size();i++){check(vm,vis,vm[sv][i]);} 
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>vm(n);
        vector<vector<int>>ans(n);
        for(int i=0;i<edges.size();i++){vm[edges[i][1]].push_back(edges[i][0]);}
        for(int i=0;i<n;i++){
            vector<int>vis(n,false);
            check(vm,vis,i);
            for(int j=0;j<n;j++){
                if(j!=i&&vis[j]){ans[i].push_back(j);}
            }
        }
        return ans;
    }
};