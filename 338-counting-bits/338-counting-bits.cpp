class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0){return {0};}
        vector<int>v(n+1);
        v[0]=0;
        v[1]=1;
        int ct=1;
        for(int i=2;i<=n;i++){
            if(i==2*ct){ct *= 2;}
            v[i] = v[i-ct]+1;
        }
        return v;
    }
};