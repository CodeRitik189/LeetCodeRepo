class Solution {
public:
    
    // best solution is linked list cycle method
    int findDuplicate(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //   while(nums[i]!=i+1){
        //     if(nums[nums[i]-1] == nums[i]){
        //         return nums[i];
        //     }
        //      swap(nums[i],nums[nums[i]-1]);
        //   }
        // }
        // return -1;
        int sl = nums[0], fast = nums[0];
        do{
            sl = nums[sl];
            fast = nums[nums[fast]];
        }while(sl!=fast);
        
        
        sl = nums[0];
        while(sl!=fast){
            sl = nums[sl];
            fast = nums[fast];
        }
        return sl;
    }
};