class Solution {
public:
    string longestPalindrome(string s) {
        int idx = -1,mx = 0;
        for(int i=0;i<s.size();i++){
            int j=i-1,k=i;
            while(j>=0&&k<s.size()&&s[j]==s[k]){
                j--;
                k++;
            }
            if(mx<k-j-1){mx = k-j-1;idx = j+1;}
            j=i-1;k=i+1;
            while(j>=0&&k<s.size()&&s[j]==s[k]){
                j--;
                k++;
            }
            if(mx<k-j-1){mx = k-j-1;idx = j+1;}
       }
        return s.substr(idx,mx);
    }
};