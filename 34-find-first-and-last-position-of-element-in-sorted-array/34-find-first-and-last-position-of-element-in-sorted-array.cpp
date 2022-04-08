class Solution {
public:
    int BS1(vector<int>& nums,int st,int endi,int tg){
        if(st>endi){
            return nums.size();
        }
        int mid = st + (endi-st)/2;
        if(nums[mid]==tg){
            return min(mid,BS1(nums,st,mid-1,tg));
        }else if(nums[mid]>tg){
            return BS1(nums,st,mid-1,tg);
        }else{
            return BS1(nums,mid+1,endi,tg);
        }
    }
    int BS2(vector<int>& nums,int st,int endi,int tg){
        if(st>endi){
            return -1;
        }
        int mid = st + (endi-st)/2;
        if(nums[mid]==tg){
            return max(0,max(mid,BS2(nums,mid+1,endi,tg)));
        }else if(nums[mid]>tg){
            return BS2(nums,st,mid-1,tg);
        }else{
            return BS2(nums,mid+1,endi,tg);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int ans1 = BS1(nums,0,nums.size()-1,target);
         int ans2 = BS2(nums,0,nums.size()-1,target);
        return {ans1==nums.size()?-1:ans1,ans2};
    }
};