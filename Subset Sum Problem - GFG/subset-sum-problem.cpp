// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int check(vector<int>arr, int sum,int n,vector<vector<int>>& dp){
        if(sum==0){return true;}
        if(sum<0||n<=0){return false;}
        if(dp[n][sum]!=-1){return dp[n][sum];}
        return dp[n][sum] = (check(arr,sum,n-1,dp)||check(arr,sum-arr[n-1],n-1,dp));
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return check(arr,sum,arr.size(),dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends