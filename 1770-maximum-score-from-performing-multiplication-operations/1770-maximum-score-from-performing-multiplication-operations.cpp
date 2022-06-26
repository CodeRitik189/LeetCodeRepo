class Solution {
public:
    vector<vector<int>>dp;
    int m , n;
//     int find(vector<int>& nums, vector<int>& multi, int i, int j){
//         if(i+n-j > m){return 0;}
        
//         if(dp[i][n-1-j] != -1){ return dp[i][n-1-j]; }
        
//       return dp[i][n-1-j] =  max(nums[i]*multi[i+n-1-j]+find(nums,multi,i+1,j) ,
//                                nums[j]*multi[i+n-1-j]+find(nums,multi,i,j-1));
//     }
    int maximumScore(vector<int>& nums, vector<int>& multi) {
           m = multi.size(), n = nums.size();
           dp = vector<vector<int>>(m+1 ,vector<int>(m+1 ,0));
           //return find(nums,multi,0,n-1);
           for(int i = 1; i<= m;i++){ dp[i][0] = dp[i-1][0]+nums[i-1]*multi[i-1];}
           for(int i = 1; i<= m;i++){ dp[0][i] = dp[0][i-1]+nums[n-i]*multi[i-1];}
        
           for(int i = 1; i<= m ; i++){
             for(int j = 1; j<= m-i; j++){
              dp[i][j] = max(nums[i-1]*multi[j+i-1]+dp[i-1][j],nums[n-j]*multi[j+i-1]+dp[i][j-1] ); 
             }
           }
          int ans = INT_MIN;
          for(int i = 0; i<= m ; i++){
             ans = max(ans,dp[i][m-i]);
          }
        return ans;
    }

}; 