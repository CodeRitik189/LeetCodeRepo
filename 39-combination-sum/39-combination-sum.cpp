class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void rec(vector<int>& cand,int ind,int tg){
        if(ind==cand.size()){return ;}
        if(tg==0){ans.push_back(v);}
        
        if(tg>=cand[ind]){
            v.push_back(cand[ind]);
            rec(cand,ind,tg-cand[ind]);
            v.pop_back();
        }else{
            return;
        }
        
        rec(cand,ind+1,tg);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        rec(candidates,0,target);
        return ans;
    }
};