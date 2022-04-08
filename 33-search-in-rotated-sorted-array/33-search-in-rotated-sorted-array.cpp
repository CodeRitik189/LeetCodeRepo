class Solution {
public:
    int BS(vector<int>& nums,int st,int endi,int tg){
        if(st>endi){
            return -1;
        }
        int mid = st + (endi-st)/2;
        if(nums[mid]==tg){
            return mid;
        }else if(nums[mid]>=nums[st]){
            if(tg>=nums[st]&&tg<=nums[mid])
             return BS(nums,st,mid-1,tg);
            else
             return BS(nums,mid+1,endi,tg);
        }else{
            if(tg<=nums[endi]&&tg>=nums[mid])
             return BS(nums,mid+1,endi,tg);
            else
             return BS(nums,st,mid-1,tg);
        }
    }
    int search(vector<int>& nums, int target) {
        return BS(nums,0,nums.size()-1,target);
    }
};