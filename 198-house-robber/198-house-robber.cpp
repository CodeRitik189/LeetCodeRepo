class Solution {
public:
    // int robbed(vector<int>& nums, int i){
    //     if(i>=nums.size()){return 0;} 
    //     return max(nums[i]+robbed(nums,i+2), robbed(nums,i+1));
    // }
    int rob(vector<int>& nums) {
        //return robbed(nums, 0 );
        if(nums.size()==1){return nums[0];}
        
        int pr1 = max(nums[0],nums[1]);
        int pr2 = nums[0];
        
        for(int i=2;i<nums.size();i++){
            int t = pr1;
            pr1 = max(pr1,pr2+nums[i]);
            pr2 = t;
        }  
        return pr1;
    }
};