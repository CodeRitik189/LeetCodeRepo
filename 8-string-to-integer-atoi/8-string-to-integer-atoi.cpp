class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
            }else{
                break;
            }
        }
        if(i==s.size()){return 0;}
        long num = 0,sign=1;
        if(s[i]=='-'){i++;sign = -1;}
        else if(s[i]=='+'){i++;sign = 1;}
        else if(!(s[i]>='0'&&s[i]<='9')){return 0;}
        while(i<s.size()&&(s[i]>='0'&&s[i]<='9')){
           num = num*10+(s[i]-'0');
           if(sign==1&&num>=INT_MAX){num=INT_MAX;break;}
           if(sign==-1&&num-1>=INT_MAX){num=INT_MIN;break;}
           i++;
        }
        return num==INT_MIN?num:sign*num;
    }
};