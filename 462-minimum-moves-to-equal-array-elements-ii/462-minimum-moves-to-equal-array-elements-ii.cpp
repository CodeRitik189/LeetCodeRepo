class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int n = nums.size(),d2 = 0,d1 = 0,ans = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i = 1; i<nums.size(); i++){
            d2 += (nums[i]-nums[0]);
        }        
        for(int i = 0; i<nums.size(); i++){
            ans = min(ans,d1+d2);
            if(i<n-1)d1 += (nums[i+1]-nums[i])*(i+1);
            if(i<n-1)d2 -= (nums[i+1]-nums[i])*(n-i-1);
        }
        return min(ans,d1+d2);
    }
};