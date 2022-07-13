class Solution {
public:
    vector<vector<int>>dp;
    bool check(string& s, int i, int l , unordered_map<string,int>& um){
        if(i==s.size())return l == 0 || um.find(s.substr(i-l,l)) != um.end();
        
        if(dp[i][l] != -1)return dp[i][l];
        
        if(um.find(s.substr(i-l,l))!=um.end() && check(s,i+1,1,um))return dp[i][l] = true;
        return dp[i][l] = check(s,i+1,l+1,um);    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>um;
        dp = vector<vector<int>>(s.size(),vector<int>(s.size()+1,-1));
        for(int i = 0; i<wordDict.size(); i++)um[wordDict[i]]++; 
        return check(s,1,1,um);
    }
};