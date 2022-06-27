// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int dfs(vector<int>vm[], int sv,  vector<int>& vis){
        vis[sv] = true;
         int ct = 0;
        for(int i = 0; i<vm[sv].size(); i++){
            if(!vis[vm[sv][i]]){
               ct +=  dfs(vm,vm[sv][i],vis);
            }
        }
        return ct+1;
    }
	int findMotherVertex(int n, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(n,0);
	    for(int i = 0; i<n; i++){
            if(!vis[i]){
               if(dfs(adj, i, vis)==n){
                   return i;
               }
            }
        }
        return -1;
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