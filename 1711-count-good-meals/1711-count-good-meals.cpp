class Solution {
public:
    int num=1000000007;
    int countPairs(vector<int>& del) {
        sort(del.begin(),del.end());
        unordered_map<int,int>um;
        int ct=0;
        for(int i=0;i<del.size();i++){
            if(del[i]==0){um[del[i]]++;continue;}
            if((del[i]&(del[i]-1))==0){ct = (ct+um[0])%num;}
            int check = (1<<(int(log2(del[i]))+1))-del[i];
            ct = (ct+um[check])%num;
            um[del[i]]++;
        }
        return ct;
    }
};