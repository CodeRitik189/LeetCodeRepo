class Solution {
public:
    vector<vector<int>> ans;
    void check(vector<int>& nums, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        // here i starts with idx because prev peemutation is also a valid ans
        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            check(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        check(nums,0);
        return ans;
    }
};