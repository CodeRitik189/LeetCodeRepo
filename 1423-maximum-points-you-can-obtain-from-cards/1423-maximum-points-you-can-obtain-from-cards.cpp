class Solution {
public:
    // quite greedy approach , move around total k elements around the both ends
    int maxScore(vector<int>& cp, int k) {
        int s = 0;
        for(int i = 0; i<k; i++){ s += cp[i]; }

        int n = cp.size(), i = 0, ans = s;
        
        while(i < k){
            s += (cp[n-i-1]-cp[k-i-1]);
            ans = max(ans,s);
            i++;
        }
        return ans;
    }
};