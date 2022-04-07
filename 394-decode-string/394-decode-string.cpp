class Solution {
public:
    string check(string& s,int st,int endi){
        if(st>endi){
            return "";
        }
        int i=st;
        string ans="";
        while(i<=endi){
           while(i<=endi&&(s[i]>='a'&&s[i]<='z')){
                ans += s[i];
                i++;
           }
           int num = 0;
           while(i<=endi&&(s[i]>='0'&&s[i]<='9')){
              num = num*10 + (s[i]-'0');
              i++;
           }
           int j = i+1;
           int ct = 1;
           while(j<=endi){
               if(s[j]=='['){
                   ct++;
               }else if(s[j]==']'){
                   ct--;
               }
               if(ct==0){
                   break;
               }
               j++;
           }
           string ansprev = check(s,i+1,j-1);
           while(num--)
             ans += ansprev;
           i = j+1;
        }
        return ans;
    }
    string decodeString(string s){
        return check(s,0,s.size()-1);
    }
};