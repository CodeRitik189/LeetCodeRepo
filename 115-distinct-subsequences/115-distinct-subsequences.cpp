class Solution {
public:
    vector<vector<int>>dp;
    int check(string& s, string& t, int i, int j){
        if(j==t.size()||i==s.size()){
            return (j==t.size());
        }
        if(dp[i][j] != -1){ return dp[i][j]; }
        int ans = 0;
        if(s[i]==t[j]){  
         ans += check(s,t,i+1,j+1);  
        }
        ans += check(s,t,i+1,j);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
       int m = s.size(), n = t.size();
       vector<double>dp(n+1,0);
       dp[0] = 1;
      // return check(s,t,0,0);
      
      for(int i=1;i<=m;i++){
          vector<double>temp(n+1,0);
          for(int j=0;j<=n;j++){
              temp[j] = dp[j];
              if(j>0&&s[i-1]==t[j-1]){
                  temp[j] += dp[j-1];
              }
          }
          dp = temp;
      }
        return (int)dp[n];
    }
};