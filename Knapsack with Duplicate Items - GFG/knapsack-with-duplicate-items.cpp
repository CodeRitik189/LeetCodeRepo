// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int check(int w, int wt[], int val[], int& n,int i,vector<vector<int>>& dp){
        if(i==n){return 0;}
        if(dp[i][w]!=-1){return dp[i][w];}
        dp[i][w] = w-wt[i]>=0?max(check(w-wt[i],wt,val,n,i,dp)+val[i],
        check(w,wt,val,n,i+1,dp)):check(w,wt,val,n,i+1,dp);
        return dp[i][w];
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return check(w,wt,val,n,0,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends