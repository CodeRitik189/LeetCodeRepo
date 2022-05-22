class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto x:s){
            nums[i++] = x;
        }
        return nums[nums.size()-k];
    }
};