// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    int nm;
    void in(int i,int j, queue<pair<int,int>>& q,vector<vector<bool>>& vis){
       if(!vis[i][j]){
        q.push({i,j});
        vis[i][j] = true;
       }
    }
    void insert(pair<int,int>& p, queue<pair<int,int>>& q,vector<vector<bool>>& vis){
        int i = p.first, j = p.second;

        if(i>1 && j>0)in(i-2,j-1,q,vis);
        if(i>1 && j<nm-1)in(i-2,j+1,q,vis);
        if(i<nm-2 && j>0)in(i+2,j-1,q,vis);
        if(i<nm-2 && j<nm-1)in(i+2,j+1,q,vis);
        if(i>0 && j>1)in(i-1,j-2,q,vis);
        if(i<nm-1 && j>1)in(i+1,j-2,q,vis);
        if(i>0 && j<nm-2)in(i-1,j+2,q,vis);
        if(i<nm-1 && j<nm-2)in(i+1,j+2,q,vis);
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int i = KnightPos[0]-1, j = KnightPos[1]-1;
	    int r = TargetPos[0]-1, c = TargetPos[1]-1;
	    nm = n;
	   vector<vector<bool>>vis(n+1,vector<bool>(n+1,0));
       queue<pair<int,int>>q;
       q.push({i,j});
       
       int ct = 0;
       
       while(!q.empty()){
          int k = q.size();
          while(k--){
            pair<int,int>p = q.front();
            if(p.first == r && p.second == c){
                return ct;
            }
            q.pop();
            insert(p,q,vis);
          }
          ct++;
       }
       return ct;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends