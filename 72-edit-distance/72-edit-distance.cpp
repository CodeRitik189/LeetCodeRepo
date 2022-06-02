class Solution {
public:
    vector<vector<int>>dp;
    int check(string& w1, string& w2, int i, int j){
        if(i<0){ return j+1;}
        if(j<0){ return i+1;}
        
        if(dp[i][j]!=-1){ return dp[i][j]; }
        
        if(w1[i]==w2[j]){
           return dp[i][j] = check(w1,w2,i-1,j-1); 
        }else{
        return dp[i][j]=1+min(check(w1,w2,i-1,j-1),min(check(w1,w2,i,j-1),check(w1,w2,i-1,j)));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        return check(word1,word2,word1.size()-1,word2.size()-1);
    }
};