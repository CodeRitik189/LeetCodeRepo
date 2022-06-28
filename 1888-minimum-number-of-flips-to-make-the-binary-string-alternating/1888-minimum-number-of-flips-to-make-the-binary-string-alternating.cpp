class Solution {
public:
    int minFlips(string s) {
        vector<vector<int>>v(2,vector<int>(2,0));
        
        for(int i = 0; i<s.size(); i++){ v[i%2][s[i]-'0']++; }
        int ans = min(v[0][0]+v[1][1],v[0][1]+v[1][0]);
        if(s.size()%2==0){return ans;}

        for(int i = 0; i<s.size(); i++){
            v[i%2][s[i]-'0'] -= 1;
            v[1-(i%2)][s[i]-'0'] += 1;
            ans = min(ans,min(v[0][0]+v[1][1],v[0][1]+v[1][0]));
        }
        return ans;
    }
};