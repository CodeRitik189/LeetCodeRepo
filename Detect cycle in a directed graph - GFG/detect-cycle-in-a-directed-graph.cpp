// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(vector<int> vm[],int sc,vector<int>& vis){
        if(vis[sc]==2){return true;}
        if(vis[sc]==1){return false;}
        vis[sc]=2;
        for(int i=0;i<vm[sc].size();i++){
            if(check(vm,vm[sc][i],vis)){return true;}
        }
        vis[sc]=1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
          if((!vis[i])&&check(adj,i,vis)){return true;}
         return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends