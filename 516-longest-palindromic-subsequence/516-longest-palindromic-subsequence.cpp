class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s1.size()+1,0));
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int m = s1.size(),n = s2.size();
        for(int i=0;i<m;i++){dp[i][0]=0;}
        for(int i=0;i<n;i++){dp[0][i]=0;}
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j] = (s1[i-1]==s2[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};