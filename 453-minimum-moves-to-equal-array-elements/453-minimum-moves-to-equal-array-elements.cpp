class Solution {
public:
    //instead of incrementing (n-1) by 1 decrement that 1 
    //beauase you can only decrement make all the elements to the smallest one
    int minMoves(vector<int>& nums) {
        long long int n = nums.size(),d2 = 0;
        int d1 = INT_MAX;
        
        for(int i = 0; i<nums.size(); i++){  d1 = min(nums[i],d1); } 
        for(int i = 0; i<nums.size(); i++){  d2 += (nums[i]-d1);   }        
        return d2;
    }
};