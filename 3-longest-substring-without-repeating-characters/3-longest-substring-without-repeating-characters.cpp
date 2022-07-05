class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int i=0,j=0,ans=0;
        // unordered_map<int,int>um;
        // while(i<s.size()){
        //     if(um.find(s[i])!=um.end()&&um[s[i]]>=j){
        //         j = um[s[i]]+1;
        //     }else{
        //         um[s[i]] = i;
        //         ans = max(ans,i-j+1);
        //         i++;
        //     }
        // }
        // return ans;
        
        int n = s.size(), ans = 0, j = 0;
    
        vector<int>hash(256,0);
        
        for(int i = 0 ; i<n;){
                if(j<i && hash[s[i]]>0){
                    hash[s[j]]--;
                    j++;
                }else{
                    hash[s[i]]++;
                    ans = max(ans,i-j+1);
                    i++;
                }     
        }
        return ans;      
    }
};