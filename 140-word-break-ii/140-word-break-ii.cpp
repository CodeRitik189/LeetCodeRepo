class Solution {
public:
    
vector<string>ans;
bool match(string& s1 , string& s2, int id){
    int i = id, j = 0;
    
    while(j<s1.size() && i<s2.size() && s1[j]==s2[i]){
        i++;
        j++;
    }
    
    if(j==s1.size())return true;
    return false;
}
void check(string &s, int idx, vector<string>& vm, string str){
    if(idx==s.size()){
        ans.push_back(str);
        return;
    }
    
    for(int i = 0 ; i<vm.size(); i++){
        if(match(vm[i],s,idx)){
            check(s,idx+vm[i].size(),vm ,str != "" ? str+' '+vm[i] : str+vm[i]);
        }
    }
}
  vector<string> wordBreak(string s, vector<string>& wordDict) {
      check(s, 0, wordDict , "");
      return ans;
    }
};