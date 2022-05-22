class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long ct1=0,ct2=0,el1=LONG_MIN,el2=LONG_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]){
                ct1++;
            }else if(el2==nums[i]){
                ct2++;
            }else if(ct1==0){
                el1=nums[i];
                ct1=1;
            }else if(ct2==0){
                el2=nums[i];
                ct2=1;
            }else{
                ct1--;
                ct2--;
            }
        }
        
        vector<int>ans;
        ct1=0;ct2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){ct1++;}
            if(nums[i]==el2){ct2++;}
        }
        
        if(ct1>nums.size()/3){ans.push_back(el1);}
        if(ct2>nums.size()/3){ans.push_back(el2);}
        
        return ans;
    }
};