class Solution {
public:
    vector<vector<int>>dp;
    int check(string& t1,string& t2,int i,int j){
    if(i==t1.size()||j==t2.size()){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    return dp[i][j]=max(t1[i]==t2[j]?1+check(t1,t2,i+1,j+1):0,
                    max(check(t1,t2,i+1,j),check(t1,t2,i,j+1)));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
        return check(text1,text2,0,0);
    }
};