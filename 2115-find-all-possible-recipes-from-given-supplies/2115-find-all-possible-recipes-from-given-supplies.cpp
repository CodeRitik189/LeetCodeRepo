class Solution {
public:
void toposort(unordered_map<string,vector<string>>& graph,vector<string>& rs,unordered_map<string,int>& vis,string str){
    if(vis[str]){return;}
    vis[str]=1;
    for(auto x:graph[str]){if(graph.find(x)!=graph.end()){toposort(graph,rs,vis,x);}}
    rs.push_back(str);
    return;
}
vector<string> findAllRecipes(vector<string>& rec,vector<vector<string>>& ing,vector<string>& sup){
       unordered_map<string,vector<string>>graph;
       unordered_map<string,int>um;
       unordered_map<string,int>vis;
       vector<string>rs;
       vector<string>ans;
       for(int i=0;i<rec.size();i++){graph[rec[i]] = ing[i];}
       for(auto str:graph){if(!vis[str.first]){toposort(graph,rs,vis,str.first);}}
       for(auto x: sup){um[x]++;}
       for(auto x:rs){
            int j;
            for(j=0;j<graph[x].size();j++){
              if(um.find(graph[x][j])==um.end()){break;}
            }
            if(j==graph[x].size()){
                um[x]++;
                ans.push_back(x);
            } 
       }
        return ans;
    }
};