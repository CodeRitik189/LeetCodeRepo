class Solution {
public:
    vector<bool>vis;
    bool check(vector<int>& nums,int k ,int idx, int sum, int& val){
        if(k==1){
            return true;
        }
        if(sum==val){
           return check(nums,k-1,0,0,val); 
        }
        for(int i = idx; i<nums.size(); i++){
            if(!vis[i] && sum+nums[i]<=val){
                vis[i] = true;
                if(check(nums,k,i+1,sum+nums[i],val))
                   return true;
                vis[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0,  n = nums.size(), mx = 0;
        for(int i = 0; i<n ; i++){
            sum += nums[i];
            mx = max(mx,nums[i]);
        }
        if(sum % k != 0 || mx>sum/k){
            return false;
        }else{
            vis = vector<bool>(n,0);
            int val = sum/k;
            return check(nums,k,0,0,val);
        }
    }
};