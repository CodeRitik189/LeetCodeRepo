class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //  unordered_map<int,int>um;
        //  int sum = 0;
        //  for(int i=0;i<nums.size();i++){
        //     if(um.find(target-nums[i])!=um.end()){
        //         return {um[target-nums[i]],i};
        //     }
        //      um[nums[i]] = i;
        //  }
        // return {};
        
        
        
        
        
        
        
        
        
        
        int n = nums.size();        
        
        for(int i  = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
        
        
        
        
        
        
    
    }
};