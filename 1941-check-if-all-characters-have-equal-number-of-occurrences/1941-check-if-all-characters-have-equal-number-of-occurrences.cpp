class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++){v[s[i]-'a']++;}
        int prev=-1;
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                if(prev!=-1&&v[i]!=prev){return false;}
                else{prev=v[i];}
            }
        }
        return true;
    }
};