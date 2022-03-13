class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       unordered_map<int,char>um;
        um['}']='{';
        um[')']='(';
        um[']']='[';
        for( int i = 0 ; i< s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            } 
            if(st.empty()||st.top()!=um[s[i]]){
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};