class Solution {
public:
    int nm = 1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int ha = hc[0], va = vc[0];
        for(int i = 1; i<hc.size(); i++){ ha = max(ha,hc[i]-hc[i-1]); }
        for(int i = 1; i<vc.size(); i++){ va = max(va,vc[i]-vc[i-1]); }  
return ((long long int)max(ha,h-hc[hc.size()-1])*(long long int)max(va,w-vc[vc.size()-1]))%nm;
    }
};