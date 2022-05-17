class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int ans = 0;
        vector<int>v(32,0);
        for(int i=0;i<cand.size();i++){
            int j=0;
            while(cand[i]>0){
                v[j++] += (cand[i]&1);
                cand[i] = cand[i]>>1;
            }
        }
        for(int i=0;i<32;i++){
            ans = max(ans,v[i]);
        }
        return ans;
    }
};