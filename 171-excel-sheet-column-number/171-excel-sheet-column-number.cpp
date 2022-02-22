class Solution {
public:
    int titleToNumber(string colstring) {
        long num=0,pow=1;
        int i=colstring.size();
        while(i--){
            num += pow*(colstring[i]-'A'+1);
            pow *= 26;
        }
        return num;
    }
};