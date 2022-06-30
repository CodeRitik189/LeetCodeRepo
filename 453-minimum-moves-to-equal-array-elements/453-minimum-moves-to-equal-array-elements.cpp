class Solution {
public:
    //instead of incrementing (n-1) by 1 decrement that 1 
    //beauase you can only decrement make all the elements to the smallest one
    int minMoves(vector<int>& nums) {
        long long int n = nums.size(),d2 = 0,d1 = 0,ans = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i = 1; i<nums.size(); i++){
            d2 += (nums[i]-nums[0]);
        }        
        return d2;
    }
};