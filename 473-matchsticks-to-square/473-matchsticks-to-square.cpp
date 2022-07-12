class Solution {
public:
    vector<int>v;
    int tsum;
    bool check(vector<int>& ms, int idx){
        if(idx==ms.size()){
            for(int i = 1; i<4; i++){
                if(v[i]!=v[i-1])return false;
            }
            return true;
        }
        if(ms[idx]>tsum/4)return false;
        
        for(int i = 0; i<4; i++){
           if(v[i]+ms[idx] <= tsum/4){
            v[i] += ms[idx];
            if(check(ms,idx+1))return true;
            v[i] -= ms[idx];
           }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0, n = matchsticks.size();
        
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        v = vector<int>(4,0);
        for(int i = 0; i<n; i++)sum += matchsticks[i];
        tsum = sum; 
        return sum%4 == 0 && check(matchsticks,0);
    }
};