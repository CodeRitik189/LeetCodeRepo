// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<vector<vector<int>>>dp;
    int check(string& s1, string& s2,int n,int m,int ct){
        if(n==0||m==0){return 0;}
        if(dp[n][m][ct]!=-1){return dp[n][m][ct];}
        if(ct==0){
            if(s1[n-1]==s2[m-1]){
                return dp[n][m][ct] = max(1+check(s1,s2,n-1,m-1,1),max(check(s1,s2,n-1,m,0),check(s1,s2,n,m-1,0)));
            }else{
                return dp[n][m][ct] = max(check(s1,s2,n-1,m,0),check(s1,s2,n,m-1,0));
            }
        }else{
            if(s1[n-1]==s2[m-1])
            return dp[n][m][ct] = 1+check(s1,s2,n-1,m-1,1);
            else
            return dp[n][m][ct] = 0;
        }
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(2,-1)));
        return check(s1,s2,n,m,0);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends