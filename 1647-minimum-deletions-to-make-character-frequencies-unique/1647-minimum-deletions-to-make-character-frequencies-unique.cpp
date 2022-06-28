class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(int i = 0; i<s.size(); i++){
            v[s[i]-'a']++;
        }
        int ct = 0;
        sort(v.begin(),v.end());
        
        for(int i = 24; i>= 0 && v[i]!=0; i--){
            if(v[i]>=v[i+1]){
                ct += min(v[i],(v[i] - v[i+1] +1));
                v[i] -= min(v[i],(v[i] - v[i+1] +1));
            }
        }
        return ct;
    }
};