class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int n = nums.size(),d2 = 0,d1 = 0,ans = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i = 1; i<nums.size(); i++){
            d2 += (nums[i]-nums[0]);
        }        
        return d2;
    }
};