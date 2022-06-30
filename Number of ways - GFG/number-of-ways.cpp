// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int>dp;
    long long int find(int n){
           if(n==0)return 1;
           if(dp[n]!=0)return dp[n];
           return dp[n] = find(n-1) + (n>=4 ? find(n-4) : 0);
    } 
    long long int arrangeTiles(int N){
        // code here
        dp = vector<long long int>(N+1,0);
        return find(N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends