// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n = str.size(), ans = INT_MAX;
        
        if(n==1){ return 1;}
        
        vector<int>v1(256,0);
        vector<int>v2(256,0);
        int ct1 = 0, ct2= 1;
        
        for(int i = 0; i<n ; i++){
            if(v1[str[i]]==0){
                ct1++;
            }
            v1[str[i]]++;
        }
        
        int i = 0, j = 0;
        
        v2[str[0]]++;
        
        while(i<n && j<n ){
            if(ct1==ct2 && j<=i){
                ans = min(ans,i-j+1);
                if(v2[str[j]]==1){
                  ct2--;
                }
                v2[str[j]]--;
                j++;
            }else{
                i++;
                if(i<n){                  
                  v2[str[i]]++;
                  if(v2[str[i]]==1){
                  ct2++;
                  }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends