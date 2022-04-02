class Solution {
public:
    int ct = 0;
    bool check(string& s,int i,int j){
        if(i>j){return true;}
        if(s[i]!=s[j]){
           if(ct==0){
               ct++;
               return check(s,i+1,j)||check(s,i,j-1);
           }else{
               return false;
           }
        }
        return check(s,i+1,j-1);
    }
    bool validPalindrome(string s) {
        return check(s,0,s.size()-1);
    }
};