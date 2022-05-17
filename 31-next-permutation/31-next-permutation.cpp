class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int idx = -1;
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]<v[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            reverse(v.begin(),v.end());
            return;
        }
        int mn=INT_MAX,id=-1;
        for(int i=v.size()-1;i>idx;i--){
            if(mn>v[i]&&v[i]>v[idx]){
                mn = v[i];
                id = i;
            }
        }
        swap(v[idx],v[id]);
        reverse(v.begin()+idx+1,v.end());
        return;
    }
};