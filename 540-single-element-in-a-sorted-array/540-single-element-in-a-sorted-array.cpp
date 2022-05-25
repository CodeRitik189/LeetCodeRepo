class Solution {
public:
    int check(vector<int>& nums,int st,int endi){
        if(st>endi){return -1;}
        
        int mid = (st+endi)/2;
        
        if(nums[mid]==nums[mid-1]){
            if(mid%2!=0){
                return check(nums,mid+1,endi);
            }else{
                return check(nums,st,mid-1);
            }
        }else if(nums[mid]==nums[mid+1]){
            if(mid%2==0){
                return check(nums,mid+1,endi);
            }else{
                return check(nums,st,mid-1);
            }
        }else{
            return nums[mid];
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1||nums[0]!=nums[1]){
           return nums[0]; 
        }
        if(nums[nums.size()-2]!=nums[nums.size()-1]){
           return nums[nums.size()-1]; 
        }
        return check(nums,1,nums.size()-2);
    }
};