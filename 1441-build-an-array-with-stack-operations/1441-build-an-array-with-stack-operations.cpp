class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int ct = 1;
        vector<string>ans;
        for(int i=0;i<target.size();i++){
            while(ct!=target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                ct++;
            }
            ans.push_back("Push");
            ct++;
        }
        return ans;
    }
};