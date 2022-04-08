class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>>um;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            um[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto x: um){
            vector<int>vi = x.second;
            vector<string>temp;
            for(int i=0;i<vi.size();i++){
                temp.push_back(strs[vi[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};