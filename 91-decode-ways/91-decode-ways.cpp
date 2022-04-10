class Solution {
public:
    vector<vector<int>>dp;
    int find(string& s, int idx, int num){
        if(num>26){
            return 0;
        }
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx][num]!=-1){
            return dp[idx][num];
        }
 return dp[idx][num] = find(s,idx+1,num*10+(s[idx]-'0'))+(s[idx]!='0'?find(s,idx+1,(s[idx]-'0')):0);
    }
    int numDecodings(string s) {
        dp = vector<vector<int>>(s.size(),vector<int>(100,-1));
        return s[0]!='0'?find(s,1,s[0]-'0'):0;
    }
};