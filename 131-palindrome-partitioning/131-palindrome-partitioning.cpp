class Solution {
public:
    vector<vector<string>>ans;
    vector<string>v;
    
    
    bool ispal(string& s ,int idx, int i){
        while(idx<i){
            if(s[i]!=s[idx]){
                return false;
            }
            i--;
            idx++;
        }
        return true;
    }
    
    void rec(string& s,int idx){
        if(idx==s.size()){ ans.push_back(v); }
        
        for(int i=idx;i<s.size();i++){
            if(ispal(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                rec(s,i+1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        rec(s,0);
        return ans;
    }
};