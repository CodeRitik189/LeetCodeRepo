class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(um[k-nums[i]]!=0){
                um[k-nums[i]]--;
                ct++;
            }else{
                um[nums[i]]++;
            }
        }
        return ct;
    }
};