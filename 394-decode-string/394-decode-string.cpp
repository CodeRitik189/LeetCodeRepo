class Solution {
public:
    string check(string& s,int st,int endi){
        if(st>endi){
            return "";
        }
        int i=st;
        string ans="";
        while(i<=endi){
           //add starting characters to ans
           while(i<=endi&&(s[i]>='a'&&s[i]<='z')){
                ans += s[i];
                i++;
           }
           int num = 0;
           //if there is a number calculate this
           while(i<=endi&&(s[i]>='0'&&s[i]<='9')){
              num = num*10 + (s[i]-'0');
              i++;
           }
           //now its confirmed that s[i] is '['
           int j = i+1;
           int ct = 1;
           
           //check the closing bracket at j for corresponding i
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
           //find ans inside this bracket using recursion and multiply acc to number
           string ansprev = check(s,i+1,j-1);
           while(num--)
             ans += ansprev;
            
           //if there further string is left give value j+1 to i for next iteration
           i = j+1;
       }
        return ans;
    }
    string decodeString(string s){
        return check(s,0,s.size()-1);
    }
};