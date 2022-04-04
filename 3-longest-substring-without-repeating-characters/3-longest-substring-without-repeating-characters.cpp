class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        vector<int>v(256,0);
        while(i<s.size()){
            v[s[i]]++;
            if(v[s[i]]>1){
                while((v[s[i]]>1&&j<i)){
                 // if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                    v[s[j]]--;
                 // }
                  j++;
                }
            }else{
                ans = max(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};