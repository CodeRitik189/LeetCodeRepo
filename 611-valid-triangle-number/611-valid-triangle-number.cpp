class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        
        for(int i=n-1; i>=2; i--){
            int k = i-1 , j = 0;
            
            while(j<k){
                if(nums[j]+nums[k]>nums[i]){
                    ans+=(k-j);
                    k--;
                }else{
                    j++; 
                }
            }
        }
        return ans;
    }
};