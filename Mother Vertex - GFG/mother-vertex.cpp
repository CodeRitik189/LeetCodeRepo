// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>vm[], int sv,  vector<int>& vis){
        vis[sv] = 1;
        for(int i = 0; i<vm[sv].size(); i++){
            if(!vis[vm[sv][i]]){
                dfs(vm,vm[sv][i],vis);
            }
        }
    }
    
	int findMotherVertex(int n, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(n,0);
	    int v = 0;
	    for(int i = 0; i<n; i++){
            if(!vis[i]){
               dfs(adj,i,vis);
               v = i;
            }
        }
        
        vis = vector<int>(n,0);
        dfs(adj,v,vis);

        for(int i = 0; i<n; i++){
            if(vis[i]==false){
                return -1;
            }
        }
        return v;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends