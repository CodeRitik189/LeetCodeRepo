class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN||x==0||x==INT_MAX){return 0;}
        int sign =  x/abs(x);
        string s = to_string(abs(x));
        int num = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(double(num)>double(INT_MAX-(s[i]-'0'))/10){
                return 0;
            }
            num = num*10+(s[i]-'0');
        }
        return sign*num;
    }
};