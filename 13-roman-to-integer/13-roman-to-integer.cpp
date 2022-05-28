class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,pair<int,int>>um;
        um['I'] = {0,1};
        um['V'] = {1,5};
        um['X'] = {2,10};
        um['L'] = {3,50};
        um['C'] = {4,100};
        um['D'] = {5,500};
        um['M'] = {6,1000};
        
        int num = 0;
        char pr = 'M';
        
        for(int i = 0; i<s.size(); i++){
           num += um[s[i]].second;
           int diff = um[s[i]].first - um[pr].first;
           if(diff==1||diff==2){
               num -= (2*um[pr].second);
           }
           pr = s[i];
        }
        return num;
    }
};