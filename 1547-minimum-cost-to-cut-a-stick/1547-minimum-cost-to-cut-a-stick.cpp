class Solution {
public:
    vector<vector<int>>dp;
    int check(vector<int>& cuts, int i, int j){
        if(i>j){ return 0; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        int ans = 1e9;
        
        for(int k = i ; k <= j ; k++){
             ans = min(ans,-cuts[i-1]+cuts[j+1]+check(cuts,i,k-1)+check(cuts,k+1,j));
        }
        return dp[i][j] = ans == 1e9 ? 0 : ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        dp = vector<vector<int>>(cuts.size(),vector<int>(cuts.size(),-1));
        
        return check(cuts,1,cuts.size()-2);
    }
};