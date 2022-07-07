class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
         int ans = 0;
         
        for(int i = 0; i<s.size(); i++){
             bool flag = true;
             vector<int>v(256,0);
            for(int j = i; j<s.size();j++){
                //entered in a substring from i to j
                if(v[s[j]]>0){
                    break;
                }
                ans = max(ans,j-i+1);
                v[s[j]]++;
            }
        }
        return ans;
    }
};