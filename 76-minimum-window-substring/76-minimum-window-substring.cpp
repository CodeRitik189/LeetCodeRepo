class Solution {
public:
    string minWindow(string s, string t) {
        
 int i = 1, j = 0, n1 = s.size(), n2 = t.size(), ans = s.size()+1, idx = -1;
        
        vector<int>v1(58,0);
        vector<int>v2(58,0);
        
        for(int k = 0; k<n2; k++){ v1[t[k]-'A']++; }      
        v2[s[0]-'A']++;
        
        while(i<=n1 && j<n1){
            bool fl = true;
            for(int k = 0; k<58; k++){
                if(v2[k]-v1[k] < 0){
                    fl = false;
                    break;
                }
            }
            if(fl){
                if(ans> i-j){
                  ans = i-j;
                  idx = j;
                }
                v2[s[j]-'A']--;
                j++;
            }else{
                if(i<n1)v2[s[i]-'A']++;
                i++;
            }
        }
        return idx == -1 ? "" : s.substr(idx,ans);
    }
};