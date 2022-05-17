class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  mn = INT_MAX,mx = 0, ans = 0;
        
        for(int i=0;i<prices.size();i++){
            if(mn>prices[i]){
                mn = prices[i];
                mx = mn;
            }else if(mx<prices[i]){
                mx = prices[i];
            }
            ans = max(ans,mx-mn);
        }
        return ans;
    }
};