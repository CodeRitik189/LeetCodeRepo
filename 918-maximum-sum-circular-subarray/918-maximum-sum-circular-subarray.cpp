class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cmax=-100000,cmin=100000,csmn=0,csmx=0,sum=0;
        for(int i=0;i<nums.size();i++){
            csmn = min(nums[i],nums[i]+csmn);
            csmx = max(nums[i],nums[i]+csmx);
            cmin = min(cmin,csmn);
            cmax = max(cmax,csmx);
            sum += nums[i];
        }
        return cmax<0?cmax:max(cmax,sum-cmin);
    }
};