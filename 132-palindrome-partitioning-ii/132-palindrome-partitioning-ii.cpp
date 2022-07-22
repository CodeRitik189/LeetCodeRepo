class Solution {
public:
    
    int ans = INT_MAX;
    bool ispal(string& s ,int idx, int i){
        while(idx<i){
            if(s[i]!=s[idx]){
                return false;
            }
            i--;
            idx++;
        }
        return true;
    }
    
    vector<int>dp;
    int rec(string& s,int idx){
        if(idx==s.size())return 0;
        int ans = 1e5;
        
        if( dp[idx]!= -1)return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(ispal(s,idx,i)){
                ans = min (ans,rec(s,i+1));
            }
        }
        return dp[idx] = 1+ans;
    }
    
    int minCut(string s) {
       dp = vector<int>(s.size(),-1);
       return rec(s,0)-1;
    }
};