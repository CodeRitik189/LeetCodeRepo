class Solution {
public:
    bool isPalindrome(int x) {
       if(x<=0){
          return x==0;
       }
        int lg = log10(x);
        int pw = pow(10,lg);
        while(pw>=10){
            if((x/pw)!=x%10){
                return false;
            }
            x = x%pw;
            x /= 10;
            pw /= 100;
        }
        return true;
    }
};