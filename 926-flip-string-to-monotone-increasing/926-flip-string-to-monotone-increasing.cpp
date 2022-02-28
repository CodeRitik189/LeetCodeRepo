class Solution {
public:
    //at any point comapare with right 0's and left 1's
    int minFlipsMonoIncr(string s) {
         int st=0,ct=0,ans=s.size();
         for(int i=0;i<s.size();i++){st += (s[i]=='0');}
         for(int i=0;i<s.size();i++){
             if(s[i]=='1'&&ans>(st+i-2*ct)){ans = st+i-2*ct;}
             else if(s[i]=='0'&&ans>(st+i-2*ct-1)){ans = st+i-2*ct-1;}
             ct += (s[i]=='0');
         }
        return ans;
    }
};