class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        unordered_map<int,int>um;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        um[i] = j;
                    }
                }
            }
        }
        
        int maxi=1,idx=0;
        
        for(int i=0; i<n ; i++){
            if(dp[i]>maxi){
                maxi = dp[i];
                idx = i;
            }
        }
        
        vector<int>ans;
        
        while(um.find(idx)!=um.end()){
            ans.push_back(nums[idx]);
            idx = um[idx];
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};