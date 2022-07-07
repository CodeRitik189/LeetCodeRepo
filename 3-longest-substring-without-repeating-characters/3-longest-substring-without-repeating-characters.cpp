class Solution {
public:
    int lengthOfLongestSubstring(string s) {  
        if(s.size()==0)return 0;
         int ans = 0;
         
        vector<int>v(256,0);
        int i = 0, j = 0;
        
        while(i<s.size()){
            if(j<i&&v[s[i]]>0){
                v[s[j]]--;
                j++;
            }else{
                v[s[i]]++;
                ans = max(ans,i-j+1);
                i++;
            }
        }
        return ans;
    }
};