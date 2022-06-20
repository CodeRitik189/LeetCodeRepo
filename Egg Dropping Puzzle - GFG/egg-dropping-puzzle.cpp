// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    
    vector<vector<int>>dp;
    int find(int n, int k){
        if(k<=1 || n == 1){ return k; }
        
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int ans = INT_MAX;
        for(int i = 1; i<k ; i++){
           ans = min(ans,max(find(n,k-i),find(n-1,i-1))); 
        }
        return dp[n][k] = 1+ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        dp = vector<vector<int>>(n+1,vector<int>(k+1,-1));
       return find(n,k);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends