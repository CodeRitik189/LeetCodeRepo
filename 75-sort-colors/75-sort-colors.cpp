class Solution {
public:
    void sortColors(vector<int>& nums) {
        // solution dekha lekin bhut bdhiya lga 
         int n = nums.size();
         int second=n-1, zero=0;
            for (int i=0; i<=second; i++) {
                while(nums[i]==2 && i<second) swap(nums[i], nums[second--]);
                while(nums[i]==0 && i>zero) swap(nums[i], nums[zero++]);
            }
    }
};