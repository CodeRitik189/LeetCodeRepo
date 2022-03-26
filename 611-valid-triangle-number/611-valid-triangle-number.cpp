class Solution {
public:
    int BS(vector<int>& nums,int st,int endi,int sum){
        if(st>endi){return -1;}
        int mid = (st+endi)/2;
        if(nums[mid]<sum){return max(mid,BS(nums,mid+1,endi,sum));}
        else{return BS(nums,st,mid-1,sum);}
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ct=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int idx = BS(nums,j+1,nums.size()-1,nums[i]+nums[j]);
                if(idx!=-1)
                ct += (idx-j);
            }
        }
        return ct;
    }
};