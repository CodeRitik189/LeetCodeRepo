class Solution {
public:
    int findpar(vector<int>& par, int val){
        while(par[val] != val){
            val = par[val];
        }
        return val;
    }
    void updatepar(vector<int>& par, int v1, int v2){
        while(par[v2] != v2){
            int val = par[v2];
            par[v2] = v1;
            v2 = val;
        }
        par[v2] = v1;
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(int i = 0; i<edges.size(); i++)n = max(n,max(edges[i][0],edges[i][1]));
        vector<int>par(n);
        for(int i = 0 ; i<n; i++)par[i] = i;
        
        for(int i = 0; i<edges.size(); i++){
            int p1 = findpar(par,edges[i][0]-1);
            int p2 = findpar(par,edges[i][1]-1);
            if(p1 == p2){
                return edges[i];
            }else{
                updatepar(par, p1<p2?edges[i][0]-1 : edges[i][1]-1, p1<p2?edges[i][1]-1 : edges[i][0]-1);
            }
        }
        return {};
    }
};