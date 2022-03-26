class Solution {
public:
    int check(vector<int>& arr, int sum,int& ts,int n,vector<unordered_map<int,int>>& dp){
        if(n<0||sum>(ts+1)/2){return false;}
        if(n==0){return 2*sum==ts;}
        if(dp[n].find(sum)!=dp[n].end()){return dp[n][sum];}
        return dp[n][sum] = (check(arr,sum,ts,n-1,dp)||check(arr,sum+arr[n-1],ts,n-1,dp));
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        vector<unordered_map<int,int>>dp(n+1);
        int ts = 0;
        for(int i=0;i<n;i++){ts += arr[i];}
        return ts%2==0&&check(arr,0,ts,n,dp);
    }
};