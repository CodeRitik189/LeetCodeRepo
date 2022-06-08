// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(vector<int>adj[] ,int sv, vector<int>& vis){
        for(int i=0; i<adj[sv].size(); i++){
           if(vis[adj[sv][i]] == -1 ){
             vis[adj[sv][i]] = 1-vis[sv];
             if(!check(adj,adj[sv][i], vis)){
                 return false;
             }
           }else if(vis[adj[sv][i]] == vis[sv]){
                 return false;
           }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
	    for(int i=0; i< V; i++){
	      if(vis[i]==-1){
	          vis[i] = 0;
	         if(!check(adj,i,vis))
	           return false;
	      }
	    }
	   return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends