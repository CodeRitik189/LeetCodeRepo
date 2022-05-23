class Solution {
public:
    //same as inversion count but looping conditions are different
    //always remember not to initialise j at every iteration of i just let it be what it is
    int ct = 0;
    
    void merge(vector<int>& nums,int st,int mid, int endi){
        vector<int>op;
        int j = mid+1;
        for(int i=st;i<=mid;i++){
            for(;j<=endi;j++){
                if(long(nums[i])<=2*long(nums[j])){
                    break;
                }
            }
            ct += (j-(mid+1));
        }
        
        int i=st;
        j=mid+1;
        while(i<=mid&&j<=endi){
            if(nums[i]>nums[j]){
                op.push_back(nums[j]);
                j++;
            }else{
                op.push_back(nums[i]);
                i++;
            }
        }
        
        while(i<=mid){
            op.push_back(nums[i++]);
        }
        while(j<=endi){
            op.push_back(nums[j++]);
        }
        
        for(int i=st;i<=endi;i++){
            nums[i] = op[i-st];
        }
        return;
    }
    void mergesort(vector<int>& nums,int st,int endi){
        if(st>=endi){return ;}
        
        int mid = (st+endi)/2;
        mergesort(nums,st,mid);
        mergesort(nums,mid+1,endi);
        
        merge(nums,st,mid,endi);
        return;
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        
        return ct;
    }
};