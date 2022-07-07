class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size(),y = s2.size(),z = s3.size();
        if(x+y!=z)return false;
        
        vector<int>dp(y+1,0);
        dp[0] = 1;
        for(int i = 1; i<= y; i++)dp[i] = s3[i-1]==s2[i-1]&&dp[i-1];
        
        for(int i=1; i<= x; i++){
            vector<int>temp(y+1,0);
            temp[0] = (s3[i-1]==s1[i-1])&&dp[0];
            
            for(int j = 1; j<= y; j++){
                temp[j] = (s3[i+j-1] == s1[i-1] && dp[j])||(s3[i+j-1] == s2[j-1] && temp[j-1]);
            }
            dp = temp;
        }
        return dp[y];
    }
};