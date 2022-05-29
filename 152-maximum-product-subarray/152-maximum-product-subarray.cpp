class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int rmax=nums[0],rmin=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(rmax,rmin);
            }
            rmax = max(rmax*nums[i],nums[i]);
            rmin = min(rmin*nums[i],nums[i]);
            
            ans = max(ans,rmax);
        }
        return ans;
    }
};