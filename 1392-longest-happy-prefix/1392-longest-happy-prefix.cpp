class Solution {
public:
    string longestPrefix(string s) {
       int n = s.size();
        vector<int>lcs(n,0);
        
        int i = 1, j = 0;
        
        while(i<n){
            if(s[i]==s[j]){
                lcs[i] = j+1;
                i++;
                j++;
            }else{
                if(j!=0){
                   j = lcs[j-1];  
                }else{
                    i++;
                }
            }
        }
        return s.substr(0,lcs[n-1]);
    }
};