class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        while(numRows-->1){
            vector<int>v;
            for(int i=0;i<=ans[ans.size()-1].size();i++){
                if(i==0){
                    v.push_back(ans[ans.size()-1][0]);
                }else if(i==ans[ans.size()-1].size()){
                    v.push_back(ans[ans.size()-1][i-1]);
                }else{
                    v.push_back(ans[ans.size()-1][i-1]+ans[ans.size()-1][i]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};