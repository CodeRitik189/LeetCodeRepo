// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<int>dp;
    int check(int n , int& x, int& y, int& z){
        if(n==0){ return 0; }
        if(n<0){ return INT_MIN; }
        
        if(dp[n] != -1){ return dp[n]; }
        
        int a1 = INT_MIN,a2 = INT_MIN,a3 = INT_MIN;
        
        a1 = check(n-x,x,y,z);
        a2 = check(n-y,x,y,z);
        a3 = check(n-z,x,y,z);
        
        int ans = max(a1,max(a2,a3));
        
        return dp[n] = (ans == INT_MIN ? ans : 1+ans);
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        dp = vector<int>(n+1,-1);
        int ans = check(n,x,y,z);
        return ans == INT_MIN ? 0 : ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends