class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int  ct = 0, oct = 1;
        
        for(int i = 1; i<nums.size();i++){
            if(nums[i] == nums[i-1] && oct%2==1){
                ct++;
            }else{
                oct++;
            }
        }
        if(oct%2 != 0){
            ct++;
        }
        return ct;
    }
};