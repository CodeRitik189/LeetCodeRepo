class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int dir,ct=0,i;
      for(i=1;i<nums.size()&&nums[i]==nums[i-1];i++);
      dir = nums[i]>nums[i-1]?1:-1;
      for(;i<nums.size()-1;i++){
          if((dir==-1&&nums[i]<nums[i+1])||(dir==1&&nums[i]>nums[i+1])){
              ct++;
              dir *= -1;
          }
      }
      return ct;
    }
};