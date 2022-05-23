class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i-1]==nums[i]){continue;}
            
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j-1]==nums[j]){continue;}
                
                int low = j+1,high = n-1; long sum = nums[i]+nums[j];
                while(low<high){
                    if(sum+long(nums[low])+long(nums[high])<target){
                        low++;
                    }else if(sum+long(nums[low])+long(nums[high])>target){
                        high--;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        int x = nums[low], y = nums[high];
                        
                        while(low<n&&x==nums[low]){low++;}
                        while(high>j&&y==nums[high]){high--;}
                    }
                }
            }
        }
        return ans;
    }
};