class Solution {
public:
    vector<int> find(string& s, int st, int endi){
        if(st==endi)return {s[st]-'0'};
        if(st==endi-1)return {(s[st]-'0')*10+(s[endi]-'0')};
        
        vector<int>ans;
        for(int i = st+1; i<endi;i++){
            if( s[i]!='*'&&s[i]!='+'&&s[i]!='/'&&s[i]!='-')continue;
            
            vector<int>v1 = find(s,st,i-1);
            vector<int>v2 = find(s,i+1,endi);
            
            for(int j = 0 ; j<v1.size();j++){
                for(int k = 0; k<v2.size();k++){
                 ans.push_back(s[i] == '+' ?  v1[j]+v2[k] : s[i]=='*' ? v1[j]*v2[k]
                             : s[i] == '/' ? v1[j]/v2[k] : v1[j]-v2[k]);
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
       return find(exp,0,exp.size()-1);
    }
};