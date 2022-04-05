class Solution {
public:
    string convert(string s, int n) {
        if(n==1){return s;}
        vector<string>vs(n,"");
        int i=0,level=0,dir=-1;
        while(i<s.size()){
            if(level==0||level==n-1){dir *= -1;}
            vs[level]+=s[i];
            i++;
            level+=dir;
        }
        string ans;
        for(int i=0;i<vs.size();i++){ans += vs[i];}
        return ans;
    }
};