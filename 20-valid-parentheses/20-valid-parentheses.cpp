class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>um;
        um[']'] = '[';
        um[')'] = '(';
        um['}'] = '{';
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(st.empty()||st.top()!=um[s[i]]){
                    return false;
                }
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};