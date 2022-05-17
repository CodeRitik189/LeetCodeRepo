class Solution {
public:
    int ct=0,mx1=-34;
//     void count(vector<int>& nums, int mask,int val,vector<bool>& check,int ct){
//             if(check[mask]){
//               return;
//             }else{
//                 check[mask] = true;
//             }
          
//              if(ct!=0){
//               if(val>mx){
//                  mx = val;
//                  mx1=1;
//               }else if(val==mx){
//                  mx1++;
//               }
//              }
//         for(int i=0;i<nums.size();i++){
//             if(!(mask&(1<<i))){
//                 count(nums,mask|(1<<i),val|nums[i],check,ct+1);
//             }
//         }
//         return;
//     }
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
         //vector<bool>check(pow(2,nums.size()+1),false);
         count(nums,0,0);
         return ct;
    }
};