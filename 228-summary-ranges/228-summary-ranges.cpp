class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
        for(int i = 0 ; i < nums.size() ;i++ ){
            string s;
            s = to_string(nums[ i ]);
            int j=i;
            while(i<nums.size()-1){
                if(nums[i] != nums[ i+1 ]-1){
                    break;
                }
                i++;
            }
            if(i != j){
            s += "->";
          s += to_string(nums[i]);
            }
            v.push_back(s);
        }
        return v;
    }
};