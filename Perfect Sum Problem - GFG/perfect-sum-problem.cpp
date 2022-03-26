// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int num = 1000000007;
	int check(int* arr, int& sum,int ts,int n,vector<unordered_map<int,int>>& dp){
        if(n<0||sum<ts){return false;}
        if(n==0){return ts==sum;}
        if(dp[n].find(ts)!=dp[n].end()){return dp[n][ts];}
        return dp[n][ts] = (check(arr,sum,ts,n-1,dp)+check(arr,sum,ts+arr[n-1],n-1,dp))%num;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<unordered_map<int,int>>dp(n+1);
        return check(arr,sum,0,n,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends