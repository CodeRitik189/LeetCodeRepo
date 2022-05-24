class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int ad) {
        vector<int>v;
        for(int i=0;i<cap.size();i++){
            v.push_back(cap[i]-rocks[i]);
        }
        sort(v.begin(),v.end());

        int ans = 0;
        for(int i=0;i<v.size();i++){
           if(ad>=v[i]){
               ad -= v[i];
               ans++;
           }else{
               break;
           }
        }
        return ans;
    }
};