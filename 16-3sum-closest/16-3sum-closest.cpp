class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int ans = INT_MAX;
       for(int i=1;i<nums.size()-1;i++){
          int j = 0,k = nums.size()-1;
          while(j<i&&k>i){
             int sum = nums[i]+nums[j]+nums[k];
             if(ans==INT_MAX||abs(target-ans)>abs(target-sum))
                ans=sum;
             if(sum<target){
                 j++;
             }else{
                 k--;
             } 
          }
       }
       return ans;
    }
};