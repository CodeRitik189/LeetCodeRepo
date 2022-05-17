class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n = nums.size(),gr = INT_MAX;
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[n-1]){
                while(!st.empty()&&st.top()<=nums[i]){
                     st.pop();
                }
                st.push(nums[i]);
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
             while(!st.empty()&&st.top()<=nums[i]){
                     st.pop();
             }
             ans[i]=st.empty()?-1:st.top();
             st.push(nums[i]);
        }
        return ans;
    }
};