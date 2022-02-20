class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& iv) {
        sort(iv.begin(),iv.end(),cmp);
        int mj=iv[0][1],ct=0;
        for(int i=1;i<iv.size();i++){
            if(iv[i][1]<=mj){
                ct++;
            }else{
                mj=iv[i][1];
            }
        }
        return iv.size()-ct;
    }
};