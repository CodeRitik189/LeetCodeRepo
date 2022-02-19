class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(),n=p.size();
        if(m<n){return {};}
        vector<int>v(26,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            v[p[i]-'a']--;
        }
        int j;
        for(j=0;j<26;j++){if(v[j]!=0){break;}}
        if(j==26){ans.push_back(0);}
        for(int i=n;i<m;i++){
            v[s[i]-'a']++;
            v[s[i-n]-'a']--;
            int j;
            for(j=0;j<26;j++){
                if(v[j]!=0){break;}
            }
            if(j==26){ans.push_back(i-n+1);}
        }
        return ans;
    }
};