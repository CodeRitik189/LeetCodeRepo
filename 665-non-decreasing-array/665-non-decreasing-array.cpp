class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==1){return true;}
        int i = 1 ;
        
        while(i<nums.size() && nums[i]>=nums[i-1]){
            i++;
        }
        
        if(i<nums.size() && i>1 && nums[i-2]>nums[i]){
            // cannot modify the previous to ith 
            // only way to change the ith to prev
            nums[i] = nums[i-1];
        }
        i++;
        while(i<nums.size() && nums[i]>=nums[i-1]){
            i++;
        }
          return i >= nums.size();
    }
};