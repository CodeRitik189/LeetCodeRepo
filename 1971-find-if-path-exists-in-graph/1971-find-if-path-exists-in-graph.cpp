class Solution {
public:
    bool check(vector<vector<int>>& graph,int sc,int dt,vector<int>& vis){
        if(sc==dt){return true;}
        if(vis[sc]){return false;}
        vis[sc]=1;
        bool ans=false;
        for(int i=0;i<graph[sc].size();i++){
            ans |= check(graph,graph[sc][i],dt,vis);
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<int>vis(n,0);
         vector<vector<int>>graph(n);
         for(int i=0;i<edges.size();i++){
             graph[edges[i][0]].push_back(edges[i][1]);
             graph[edges[i][1]].push_back(edges[i][0]);
         }
        return check(graph,source,dest,vis);
    }
};