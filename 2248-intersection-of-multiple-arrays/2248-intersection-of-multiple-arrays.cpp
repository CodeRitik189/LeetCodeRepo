class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
         vector<int>ans;
         unordered_map<int,int>um;
        for(int j=0;j<nums[0].size();j++) um[nums[0][j]]++;
        
        for(int i=1;i<nums.size();i++){
            unordered_map<int,int>temp;
            for(int j=0;j<nums[i].size();j++){
                if(um.find(nums[i][j])!=um.end()){
                    temp[nums[i][j]]++;
                }
            }
            um = temp;
        }
        for(auto x:um)ans.push_back(x.first);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};