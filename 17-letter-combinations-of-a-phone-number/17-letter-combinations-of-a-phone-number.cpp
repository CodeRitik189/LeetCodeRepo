class Solution {
public:
    vector<string> num = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> check(string& dig,int idx){
        if(idx==-1){
            return {""};
        }
        vector<string> ans;
        vector<string> prev = check(dig,idx-1);
        
        for(int i=0;i<prev.size();i++){
            for(int j=0;j<num[dig[idx]-'0'].size();j++)
              ans.push_back(prev[i]+num[dig[idx]-'0'][j]);
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        return check(digits,digits.size()-1);
    }
};