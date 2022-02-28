class Solution {
public:
    int minFlipsMonoIncr(string s) {
         int st=0,ans=s.size();
         vector<int>v(s.size());
         for(int i=0;i<s.size();i++){
             v[i]= st;
             st += (s[i]=='0');
         }
         for(int i=0;i<s.size();i++){
             if(s[i]=='1'&&ans>(st-v[i]+i-v[i])){
                 ans = st-v[i]+i-v[i];
             }else if(s[i]=='0'&&ans>(st-v[i]+i-v[i]-1)){
                 ans = st-v[i]+i-v[i]-1;
             }
         }
        return ans;
    }
};