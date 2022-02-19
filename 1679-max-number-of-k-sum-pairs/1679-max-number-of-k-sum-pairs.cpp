class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>um;
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(um[k-nums[i]].size()!=0){
                um[k-nums[i]].pop_back();
                ct++;
            }else{
                um[nums[i]].push_back(i);
            }
        }
        return ct;
    }
};