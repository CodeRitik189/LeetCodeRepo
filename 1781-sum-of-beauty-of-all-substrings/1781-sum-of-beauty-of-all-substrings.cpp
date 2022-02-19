class Solution {
public:
    //simple brute force solution easy to understand
    int beautySum(string s) {
        int n=s.size(),sum=0;
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
               int mn = INT_MAX,mx = INT_MIN;
               v[s[j]-'a']++;
               for(int k=0;k<26;k++){
                   if(v[k]!=0){
                    mn=min(mn,v[k]);
                    mx=max(mx,v[k]);
                   }
               }
               sum += (mx-mn); 
            }
        }
        return sum;
    }
};