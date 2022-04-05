class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        vector<int>v(256,0);
        while(i<s.size()){
            if(v[s[i]]>0){
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