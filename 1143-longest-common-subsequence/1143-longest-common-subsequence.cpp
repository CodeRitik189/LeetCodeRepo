class Solution {
public:
    // vector<vector<int>>dp;
    // int check(string& t1,string& t2,int i,int j){
    // if(i==t1.size()||j==t2.size()){return 0;}
    // if(dp[i][j]!=-1){return dp[i][j];}
    // return dp[i][j]=(t1[i]==t2[j]?1+check(t1,t2,i+1,j+1):
    //                 max(check(t1,t2,i+1,j),check(t1,t2,i,j+1)));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // dp = vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
        // return check(text1,text2,0,0);
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int m = text1.size(),n = text2.size();
        for(int i=0;i<m;i++){dp[i][0]=0;}
        for(int i=0;i<n;i++){dp[0][i]=0;}
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j] = (text1[i-1]==text2[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};