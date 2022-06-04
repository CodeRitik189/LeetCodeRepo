class Solution {
public:
    static bool cmp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
    
    bool check(string& s1, string& s2){
        int i = 0,j = 0, ct = 0;
        
        while(i<s1.size()){
            if(s1[i]!=s2[j]){
                if(ct==0){
                    ct++;
                }else{
                    return false;
                }
                j++;
            }else{
                i++;j++;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
      
        int n = words.size();
        vector<int>dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if( words[i].size()-words[j].size()==0 ){ continue; }
                if( words[i].size()-words[j].size()>1 ){ break; }
                
                if(check(words[j],words[i])){
                   dp[i] = max(dp[i],dp[j]+1); 
                }
            }
        }
        int maxi=1;
        
        for(int i=0; i<n ; i++){
            maxi = max(maxi,dp[i]);
        }  
        return maxi;
    }
};