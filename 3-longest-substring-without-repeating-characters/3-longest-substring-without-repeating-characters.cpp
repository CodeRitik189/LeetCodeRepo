class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        // vector<int>v(256,0);
        // while(i<s.size()){
        //     if(v[s[i]]>0){
        //         v[s[j]]--;
        //         j++; 
        //     }else{
        //         v[s[i]]++;
        //         ans = max(ans,i-j+1);
        //         i++;
        //     }
        // }
        // return ans;
        unordered_map<int,int>um;
        while(i<s.size()){
            if(um.find(s[i])!=um.end()&&um[s[i]]>=j){
                j = um[s[i]]+1;
            }else{
                um[s[i]] = i;
                ans = max(ans,i-j+1);
                i++;
            }
        }
        return ans;
    }
};