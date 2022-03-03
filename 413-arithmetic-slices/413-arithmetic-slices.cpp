class Solution {
public:
    // first approach was a o(N) space approach but new one is better 
    /*vector<unordered_map<int,int>>dp(nums.size());
        for(int i=1;i<nums.size();i++){
            dp[i][nums[i]-nums[i-1]] = dp[i-1][nums[i]-nums[i-1]]+1;
            dp[i-1][nums[i]-nums[i-1]] = 0;
        }
        for(int i=0;i<dp.size();i++){
            for(auto j : dp[i]){
                if(j.second>=2){
                    ans += (((j.second)*(j.second-1))/2);
                }
            }
        }*/
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        if(nums.size()<3){return 0;}
        int prev = nums[1]-nums[0],ct=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==prev){
                ct++;
            }else{
                ans += ((ct-1)*(ct-2))/2;
                ct=2;
                prev = nums[i]-nums[i-1];
            }
        }
        if(ct>2){ans += ((ct-1)*(ct-2))/2;}
       return ans;
    }
};