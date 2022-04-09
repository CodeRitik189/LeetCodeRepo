class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        vector<vector<int>> ans;
        sort(itv.begin(), itv.end());
        
        int st = itv[0][0];
        int end = itv[0][1];
        
        for(int i=1; i<itv.size(); i++){
            if(itv[i][0]>end){
              ans.push_back({st,end});
              st = itv[i][0];
              end = itv[i][1];
            }else{
              end = max(end,itv[i][1]);
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};