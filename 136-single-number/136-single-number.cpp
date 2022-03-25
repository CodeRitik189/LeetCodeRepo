class Solution {
public:
    //log(n) code for sorted array
   /* int check(vector<int>& nums,int st,int endi){
        if(st>endi){return -1;}
        int mid = st+(endi-st)/2;
        if((nums[mid]!=nums[mid-1])&&(nums[mid]!=nums[mid+1])){
            return nums[mid];
        }else if(nums[mid]==nums[mid-1]){
            if(mid%2==0){
                return check(nums,st,mid-1);
            }else{
                return check(nums,st,mid+1);
            }
        }else{
            if(mid%2==0){
                return check(nums,st,mid+1);
            }else{
                return check(nums,st,mid-1);
            }
        }
    }*/
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int i=0;i<nums.size();i++){
            xr ^= nums[i];
        }
        return xr;
    }
};