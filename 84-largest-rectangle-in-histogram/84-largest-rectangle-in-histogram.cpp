class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0 , n = heights.size();
        stack<int>st;
        
        for(int i=0 ; i<=n ; i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int temp = st.top();
                st.pop();
                
                int ht = heights[temp];
                int wt = !st.empty() ? i - st.top()-1 : i;
                
                ans = max(ans,wt*ht);
            }
            st.push(i);
        }

        return ans;
    }
};