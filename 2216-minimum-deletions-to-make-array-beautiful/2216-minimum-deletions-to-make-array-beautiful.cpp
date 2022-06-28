class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int prev = 0, ct = 0, oct = 1;
        
        for(int i = 1; i<nums.size();i++){
            if(nums[i] == nums[prev] && oct%2==1){
                ct++;
            }else{
                oct++;
            }
            prev = i;
        }
        if(oct%2 != 0){
            ct++;
        }
        return ct;
    }
};