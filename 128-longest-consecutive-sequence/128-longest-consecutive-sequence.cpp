class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(um.find(nums[i]-1)==um.end()){
                int ct = 0,nm = nums[i];
                
                while(um.find(nm)!=um.end()){
                    ct++;
                    nm++;
                }
                
                ans = max(ans,ct);
            }
        }
        return ans;
    }
};