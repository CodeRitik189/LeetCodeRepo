class Solution {
public:
    int sz;
    vector<string>vs;
    void check(string s,int ct){
        if(ct<0){return;}
        if(s.size()==2*sz){
          if(ct==0){
              vs.push_back(s);
          }  
           return;
        }
        check(s+')',ct-1);
        check(s+'(',ct+1);
    }
    vector<string> generateParenthesis(int n) {
        sz = n;
        check("",0);
        return vs;
    }
};