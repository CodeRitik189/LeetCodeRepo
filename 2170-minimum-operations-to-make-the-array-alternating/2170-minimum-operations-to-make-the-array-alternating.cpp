class Solution {
public:
    vector<int> check(unordered_map<int,int>& um){
        int I = INT_MIN, Is, II = INT_MIN ;
        
        for(auto x: um){
            if(x.second > I){
                II = I;
                I = x.second;
                Is = x.first;
            }else if(x.second > II){
                II = x.second;
            }
        }
        return {Is,I,max(II,0)};
    }
    int minimumOperations(vector<int>& nums) {
        if(nums.size()==1){return 0;}
        
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(int i = 0; i<nums.size(); i++){
            if(i%2==0){
                m1[nums[i]]++ ;
            }else{
               m2[nums[i]]++;
            }
        }
       vector<int>v1 = check(m1);
       vector<int>v2 = check(m2);

        if(v1[0]==v2[0]){
           return nums.size()-max(v1[1]+v2[2],v2[1]+v1[2]);
        }else{
           return nums.size()-(v1[1]+v2[1]); 
        }
    }
};