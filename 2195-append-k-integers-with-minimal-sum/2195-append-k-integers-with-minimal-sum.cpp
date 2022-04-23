class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long int ans = 0,pr=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pr){continue;}
            if(nums[i]-pr-1<=k){
                ans += (long(nums[i]-1)*nums[i])/2-(long(pr+1)*pr)/2;
                k -= (nums[i]-pr-1);
            }else{
                ans += (long(pr+k+1)*(pr+k))/2-(long(pr+1)*pr)/2;
                k = 0;  
                break;
            }
            pr = nums[i];
        }
        if(k>0){
          ans += (long(pr+k+1)*(pr+k))/2-(long(pr+1)*pr)/2;
        }
        return ans;
    }
};