class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, j = 0, st = 0, n = gas.size();
       while(j<n && (i-j)<n){
           if(i>=n){
               st += (gas[i-n]- cost[i-n]);
           }else{
               st += (gas[i]- cost[i]);
           }
           if(st<0){
               st = 0;
               j = i+1;
           }
              i++;
       }
       
       if(j>=n){
           return -1;
       }
       return j;
    }
};