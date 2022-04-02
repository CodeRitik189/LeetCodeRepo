class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0,k=pref.size();
            while(j<min(strs[i].size(),pref.size())&&strs[i][j]==pref[j]){
                j++;
            }
            while(j<k){
                pref.pop_back();
                j++;
            }
        }
        return pref;
    }
};