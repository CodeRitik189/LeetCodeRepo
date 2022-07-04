class Solution {
public:
    void sortColors(vector<int>& nums) {
        // solution dekha lekin bhut bdhiya lga 
        
        int n = nums.size();
        int z = 0, t = n-1;
        
        for(int i = 0; i<n; i++){
            while(i<t && nums[i]==2){
                swap(nums[i],nums[t]);
                t--;
            }
            while(i>z && nums[i]==0){
                swap(nums[i],nums[z]);
                z++;
            }
        }
    }
};
