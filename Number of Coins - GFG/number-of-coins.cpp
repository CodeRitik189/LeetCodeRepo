// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	unordered_map<int,int>dp;
    int check(int* coins,int amt,int n){
        if(amt<0){return 1000000;}
        if(amt==0){return 0;}
        if(dp.find(amt)!=dp.end()){return dp[amt];}
        int ans = 1000000;
        for(int i=0;i<n;i++){
            ans = min(ans,check(coins,amt-coins[i],n));
        }
        return dp[amt]=(ans==1000000?ans:1+ans);
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int ans = check(coins,V,M);
        return ans==1000000?-1:ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends