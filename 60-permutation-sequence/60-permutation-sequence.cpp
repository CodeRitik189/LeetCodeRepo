class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fact = 1;
        
        for(int i=1;i<n;i++){
            v.push_back(i);
            fact = fact*i;
        }
        
        k--;
        v.push_back(n);
        string ans = "";
        
        while(true){
            ans += to_string(v[k/fact]);
            v.erase(v.begin()+(k/fact));
            k = k%fact;
            if(v.size()==0){
                break;
            }
            fact = fact/v.size();
        }
        return ans;
    }
};