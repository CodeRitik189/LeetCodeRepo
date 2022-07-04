class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i<s.size(); i++){
            if(s[i] >='a' && s[i]<= 'z')s[i] -= 32;
        }
        
        int i = 0,  j = s.size()-1;
        
        while(i<j){
            if(!(s[j]>='A'&&s[j]<='Z')&&!((s[j]>='0'&&s[j]<='9'))){
                j--;
            }else if(!(s[i]>='A'&&s[i]<='Z')&&!((s[i]>='0'&&s[i]<='9'))){
                i++;
            }else if(s[i]!=s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};