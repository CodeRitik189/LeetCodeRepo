class Solution {
public:
    string longestPalindrome(string s) {
        vector<int>dp(s.size(),0);
        for(int i=0;i<s.size();i++){
              int j=i-1,k=i;
              while(j>=0&&k<s.size()&&s[j]==s[k]){
                j--;
                k++;
              }
              dp[j+1] = k-j-1;
            j=i-1;k=i+1;
            while(j>=0&&k<s.size()&&s[j]==s[k]){
                j--;
                k++;
            }
            dp[j+1] = max(dp[j+1],k-j-1);
       }
        int idx = -1,mx = 0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>mx){mx = dp[i];idx = i;}
        }
        return s.substr(idx,mx);
    }
};