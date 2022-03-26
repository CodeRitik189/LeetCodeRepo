// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int gsum,ans=INT_MAX;
    void check(int arr[],int n,int sum,vector<unordered_map<int,int>>& dp){
        if(n==0){return;}
        if(dp[n].find(sum)!=dp[n].end()){return;}
        ans = min(ans,abs(gsum-2*sum));
        check(arr,n-1,sum,dp);
        check(arr,n-1,sum+arr[n-1],dp);
        dp[n][sum]=0;
        return;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0;i<n;i++){sum += arr[i];}
	    gsum = sum;
	    vector<unordered_map<int,int>>dp(n+1);
	    check(arr,n,0,dp);
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends