// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void Sort(vector<int> adj[], int sv, vector<int>& vis,vector<int>& v){
	   vis[sv] = true;
	   
	   for(int i=0; i<adj[sv].size(); i++){
	      if(!vis[adj[sv][i]])
	       Sort(adj, adj[sv][i], vis, v);
	   }
	    v.push_back(sv);
	}
	
	vector<int>SortDFS(int V, vector<int> adj[]){
	    vector<int>vis(V,0);
	    vector<int>v;
	    
	    for(int i=0; i<V; i++)
	      if(!vis[i])Sort(adj,0,vis,v);
	     
	    reverse(v.begin(),v.end()); 
	    return v;
	}
	
	vector<int> SortBFS(int V, vector<int> adj[]){
	    vector<int>ans;
	    vector<int>indg(V,0);
	    queue<int>q;
	    
	    for(int i=0;i<V;i++){
	        for(int j=0; j<adj[i].size(); j++){
	            indg[adj[i][j]]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indg[i]==0){ q.push(i); }
	    }
	    
	    while(!q.empty()){
	        int t = q.front();
	        q.pop();
	        ans.push_back(t);
            
            for(int i= 0; i<adj[t].size();i++){
                indg[adj[t][i]]--;
                if(indg[adj[t][i]]==0){
                    q.push(adj[t][i]);
                }
            }
	    }
	    return ans;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // return SortDFS(V,adj);
	    return SortBFS(V,adj);
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends