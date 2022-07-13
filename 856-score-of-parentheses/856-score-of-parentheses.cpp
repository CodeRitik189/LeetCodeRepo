class Solution {
public:
    int find(string& s, int i, int j){
        if(i>j)return 1;
        
        int ans = 0;
        while(i<j){
          int k = i+1, st = 1;
          while(k<=j){
              s[k]==')'?st--:st++;
              if(st==0)break;
              else k++;
          }
          ans += find(s,i+1,k-1);
          i = k+1;
        }
       return 2*ans;
    }
    int scoreOfParentheses(string s) {
        return find(s,0,s.size()-1)/2;
    }
};