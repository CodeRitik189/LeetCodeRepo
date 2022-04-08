class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]==0&&i+nums[i]>=mx){
                return false;
            }
            mx = max(mx,i+nums[i]);
        }
        return mx>=nums.size()-1;
    }
};