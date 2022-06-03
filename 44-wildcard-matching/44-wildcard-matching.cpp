class Solution {
public:
    vector<vector<int>>dp;
    bool check(string& s, string& t, int i , int j){
        if(j==t.size()){   return i==s.size();    }
        if(i==s.size()){   return (t[j]=='*'&&check(s,t,i,j+1));  }
        
        if(dp[i][j]!=-1){ return dp[i][j]; }
        
        if(s[i]==t[j]){
            dp[i][j] = check(s,t,i+1,j+1);  
        }else{
            
            if(t[j]=='?'){
                 dp[i][j] = check(s,t,i+1,j+1);
            }else if(t[j]=='*'){
                dp[i][j] = (check(s,t,i+1,j+1)||check(s,t,i+1,j)||check(s,t,i,j+1));
            }else{
                dp[i][j] = false;
            }
            
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        return check(s,p,0,0);
    }
};