// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<int>dp;
    int N;
    int check(int* price,int n){
        if(n<=0){return 0;}
        if(dp[n]!=-1){return dp[n];}
        for(int i=1;i<=N;i++){
          if(n>=i)
          dp[n] = max(dp[n],price[i-1]+check(price,n-i));
        }
        return dp[n];
    }
    int cutRod(int price[], int n) {
        N = n;
        dp = vector<int>(n+1,-1);
        return check(price,n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends