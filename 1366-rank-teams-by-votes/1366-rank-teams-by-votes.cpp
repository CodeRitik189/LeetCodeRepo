class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        return v1>v2;
    }
    string rankTeams(vector<string>& votes) {
        vector<vector<int>>v(26,vector<int>(27,0));
        
        for(int i = 0; i<26; i++){
           v[i][26] = 25-i;
        }
        for(int i = 0; i<votes.size(); i++){
            for(int j = 0; j<votes[i].size(); j++)
               v[votes[i][j]-'A'][j]++;
        }
        
        sort(v.begin(),v.end(),cmp);
        string ans = "";
        
        for(int i = 0 ; i<26; i++){
            bool fl = false;
            for(int j = 0; j<26; j++){
                if(v[i][j] >0){
                    fl = true;
                    break;
                }
            }
            if(fl){
                ans += ((25-v[i][26])+'A');
            }else{
                break;
            }
        }
        return ans;
    }
};