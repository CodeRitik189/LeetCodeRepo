// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int check(int* arr, int sum,int& ts,int n,vector<unordered_map<int,int>>& dp){
        if(n<0||sum>(ts+1)/2){return false;}
        if(n==0){return 2*sum==ts;}
        if(dp[n].find(sum)!=dp[n].end()){return dp[n][sum];}
        return dp[n][sum] = (check(arr,sum,ts,n-1,dp)||check(arr,sum+arr[n-1],ts,n-1,dp));
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        vector<unordered_map<int,int>>dp(n+1);
        int ts = 0;
        for(int i=0;i<n;i++){ts += arr[i];}
        return ts%2==0&&check(arr,0,ts,n,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends