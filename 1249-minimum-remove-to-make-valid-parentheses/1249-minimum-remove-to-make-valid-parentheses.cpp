class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n1=0;    
        for(int i=0;i<s.size();i++){
            if(s[i]!='('&&s[i]!=')'){
                continue;
            }else if(s[i]!='('){
                n1--;
            }else{
                n1++;
            }
            if(n1<0){
                s[i]=0;
                n1=0;
            }
        }
        n1=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='('&&s[i]!=')'){
                continue;
            }else if(s[i]!='('){
                n1++;
            }else{
                n1--;
            }
            if(n1<0){
                s[i]=0;
                n1=0;
            }
        }
        string s1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=0){
                s1+=s[i];
            }
        }
        return s1;
    }
};