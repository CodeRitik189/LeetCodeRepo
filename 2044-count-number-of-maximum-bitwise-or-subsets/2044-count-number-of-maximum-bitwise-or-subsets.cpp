class Solution {
public:
    int ct=0,mx1=-34;
    void count(vector<int>& nums,int val,int idx){
        if(idx==nums.size()){
            if(val>mx1){
               ct = 1;
               mx1 = val;
            }else if(val==mx1){
                ct++;
            }
            return;
        }
        count(nums,val|nums[idx],idx+1);
        count(nums,val,idx+1);
        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
         count(nums,0,0);
         return ct;
    }
};