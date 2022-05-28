class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int , char>um;
        um[0] = 'I'; um[1] = 'V'; um[2] = 'X';
        um[3] = 'L'; um[4] = 'C'; um[5] = 'D';
        um[6] = 'M';
        
        unordered_map<int,vector<int>>um2;
        um2[0] = {}; um2[1] = {0}; um2[2] = {0,0}; um2[3] = {0,0,0}; um2[4] = {1,0}; 
        um2[5] = {1};um2[6] = {0,1};um2[7] = {0,0,1};um2[8] = {0,0,0,1};um2[9] = {2,0};
        
        string s = "";
        int idx = 0;
        
        while(num != 0){
            vector<int>v = um2[num%10];
            
            for(int i=0; i<v.size(); i++){
                s += um[v[i]+idx];
            }
            idx += 2;
            num /= 10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};