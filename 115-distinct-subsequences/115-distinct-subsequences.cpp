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
       dp = vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
       return check(s,t,0,0);
    }
};