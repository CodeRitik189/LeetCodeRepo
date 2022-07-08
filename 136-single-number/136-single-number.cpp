class Solution {
public:
    // 1 1 2 2 3 4 4
    // 0 1 2 3 4 5 6 
    
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return nums[0];
        
        int st = 0, endi = nums.size()-1;
      while(st<= endi){
        int mid = st+(endi-st)/2;
        
        if(mid<nums.size()-1 && nums[mid]==nums[mid+1]){
            if(mid%2==0)st = mid+1;
            else endi = mid-1;
        }else if(mid>0 && nums[mid]==nums[mid-1]){
            if(mid%2!=0)st = mid+1;
            else endi = mid-1;
        }else{
            return nums[mid];
        }
      }
        return -1;
    }
};