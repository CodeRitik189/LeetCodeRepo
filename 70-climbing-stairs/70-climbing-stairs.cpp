class Solution {
public:
    vector<int>v;
    int climb(int n){
        if(n<=0){
            return n==0;
        }
        if(v[n]!=-1){
            return v[n];
        }
        return v[n] = climb(n-1)+climb(n-2);
    }
    int climbStairs(int n) {
        v = vector<int>(n+1,-1);
        return climb(n);
    }
};