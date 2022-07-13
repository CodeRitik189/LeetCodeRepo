class Solution {
public:
    int numSplits(string s) {
        unordered_map<int,int>um;
        
        int n = s.size(),ct = 0, ans = 0;
        
        vector<int>count(n);
        for(int i = n-1; i>=0; i--){
            count[i] = ct;
            um[s[i]]++;
            if(um[s[i]]==1)ct++;
        }
        
        um.clear(); ct = 0;
        for(int i = 0; i<n-1; i++){
            um[s[i]]++;
            if(um[s[i]]==1)ct++;
            if(ct == count[i])
                ans++;
        }
        return ans;
    }
};