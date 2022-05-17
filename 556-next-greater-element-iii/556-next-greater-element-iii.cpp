class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        while(n!=0){
            v.push_back(n%10);
            n /= 10;
        }
        int idx = -1;
        for(int i=1;i<v.size();i++){
            if(v[i]<v[i-1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            return -1;
        }
        int mn=INT_MAX,id=-1;
        for(int i=0;i<idx;i++){
            if(mn>v[i]&&v[i]>v[idx]){
                mn = v[i];
                id = i;
            }
        }
        swap(v[idx],v[id]);
        reverse(v.begin(),v.begin()+idx);
        
        long ans = 0;
        for(int i=v.size()-1;i>=0;i--){
            ans = ans*10 + v[i];
        }
        return ans>INT_MAX?-1:ans;
    }
};