class Solution {
public:
    //u can simply do xor rather than counting bits
    int maximumXOR(vector<int>& nums) {
//         vector<int>v(32,0);
//         for(int i = 0; i<nums.size();i++){
//             for(int j = 0; j<32; j++){
//                 if((nums[i]&(1<<j)) != 0){
//                     v[j] = 1;
//                 }
//             }
//         }
//         int ans = 0;
        
//         for(int i = 0; i<32; i++){
//             if(v[i]==1)
//              ans += (1<<i);
//         }
//         return ans;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans |= nums[i];
        }
        return ans;
    }
};