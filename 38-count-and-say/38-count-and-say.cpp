class Solution {
public:
   string check(int n){
     if(n==1){
         return "1";
     }
     string prev = check(n-1);
     string ans = "";
     for(int i = 0; i<prev.size();){
         int j = i+1;
         while(j<prev.size()&&prev[j]==prev[i]){
             j++;
         }
         ans += (j-i+'0');
         ans += (prev[i]);
         i = j;
     }
      return ans;
   }
    string countAndSay(int n) {
        return check(n);
    }
};