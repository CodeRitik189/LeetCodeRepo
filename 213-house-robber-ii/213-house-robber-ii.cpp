class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        int pr1 = max(nums[0],nums[1]), n= nums.size();
        int pr2 = nums[0];
        int pr3 = max(nums[n-2],nums[n-1]);
        int pr4 = nums[n-1];
        
        for(int i=2;i<nums.size()-1;i++){
            int t = pr1;
            pr1 = max(pr1,pr2+nums[i]);
            pr2 = t;
        }  
        
        for(int i=nums.size()-3;i>0;i--){
            int t = pr3;
            pr3 = max(pr3,pr4+nums[i]);
            pr4 = t;
        }  
        return max(pr3,pr1);
    }
};