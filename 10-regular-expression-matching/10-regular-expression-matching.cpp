class Solution {
public:
    
    bool check(string& s, string& p, int i, int j){
        if(i == s.size() && j == p.size())return true;
        else if(j == p.size())return false;
        else if(i == s.size())return j<p.size()-1 && p[j+1]=='*' && check(s,p,i,j+2);
        
        if(j<p.size()-1 && p[j+1]=='*'){
            if((p[j] == '.'|| s[i] == p[j]) && (check(s,p,i+1,j)||check(s,p,i+1,j+2)))return true;
            return check(s,p,i,j+2);
        }
        return ( (p[j] == '.'|| s[i] == p[j]) && check(s,p,i+1,j+1) );
    }
    bool isMatch(string s, string p) {
        return check(s,p,0,0);
    }
};