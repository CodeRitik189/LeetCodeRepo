class Solution {
public:
    vector<int>ans;
    bool check(vector<vector<int>>& vm,vector<int>& vis,int sv){
        if(vis[sv]!=-1){return vis[sv];}
        vis[sv]=0;
        bool ch = true;
        for(int i=0;i<vm[sv].size();i++){ch &= check(vm,vis,vm[sv][i]);}
        if(ch){ans.push_back(sv);}
        vis[sv]=ch;
        return ch;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){if(vis[i]==-1){check(graph,vis,i);}}
        sort(ans.begin(),ans.end());
        return ans;
    }
};