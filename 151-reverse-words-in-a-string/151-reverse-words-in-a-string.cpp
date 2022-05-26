class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string t="",ans="";
        vector<string>v;
        
        while(i<s.size()){
            while(i<s.size()&&s[i]==' '){
                i++;
            }
            while(i<s.size()&&s[i]!=' '){
                t += s[i];
                i++;
            }
            if(t.size()!=0)
             v.push_back(t);
            t = "";
        }
        
        for(int i=v.size()-1;i>=1;i--){
            ans += v[i];
            ans += ' ';
        }
        ans += v[0];
        return ans;
    }
};