class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m;i++){dp[i][0]=0;}
        for(int i=0;i<n;i++){dp[0][i]=0;}
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j] = (text1[i-1]==text2[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]));
            }
        }
        
        int i = m,j = n;
        string ans = "";
        
        while(i>0&&j>0){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans += text1[i-1];
                    i--;
                }else{
                    ans += text2[j-1];
                    j--;
                }
            }
        }
        
        while(i>0){
            ans += text1[i-1];
            i--;
        }
        while(j>0){
            ans += text2[j-1];
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};