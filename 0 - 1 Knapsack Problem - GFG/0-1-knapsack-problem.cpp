// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    /*int check(int w, int wt[], int val[], int& n,int i,vector<vector<int>>& dp){
        if(i==n){return 0;}
        if(dp[i][w]!=-1){return dp[i][w];}
        dp[i][w] = w-wt[i]>=0?max(check(w-wt[i],wt,val,n,i+1,dp)+val[i],check(w,wt,val,n,i+1,dp)):check(w,wt,val,n,i+1,dp);
        return dp[i][w];
    }*/
    int knapSack(int w, int wt[], int val[], int n) 
    { 
     //   vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
     //   return check(w,wt,val,n,0,dp);
      vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
      for(int i=0;i<=n;i++){dp[i][0]=0;}
      for(int i=0;i<=w;i++){dp[0][i]=0;}
      for(int i=1;i<=n;i++){
          for(int j=1;j<=w;j++){
              if(j>=wt[i-1])
              dp[i][j] = max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
              else
              dp[i][j] = dp[i-1][j];
          }
      }
      return dp[n][w];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends