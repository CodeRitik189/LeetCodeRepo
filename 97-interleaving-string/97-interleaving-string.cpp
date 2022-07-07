class Solution {
public:
    vector<vector<int>>dp;
    bool check(string& s1, string& s2, string& s3, int i, int j, int k){
        if(i<0 || j<0){
            if(k<0)return (i<0&&j<0);
            else if(i>=0)return (s1[i]==s3[k]&&check(s1,s2,s3,i-1,j,k-1));
            else if(j>=0)return (s2[j]==s3[k]&&check(s1,s2,s3,i,j-1,k-1));
            return false;  
        }
    if(dp[i][j]!=-1)return dp[i][j];  
    if(s1[i]!=s3[k] && s2[j]!=s3[k])return dp[i][j] = false;
        
  return dp[i][j] = (s1[i]==s3[k]&&check(s1,s2,s3,i-1,j,k-1))||(s2[j]==s3[k]&&check(s1,s2,s3,i,j-1,k-1));
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size(),y = s2.size(),z = s3.size();
        dp = vector<vector<int>>(x,vector<int>(y,-1));
        return x+y==z&&check(s1,s2,s3,x-1,y-1,z-1);
    }
};