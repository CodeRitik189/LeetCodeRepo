// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    vector<vector<int>>dp;
    int check(string& s, string& t, int i, int j){
        if(i==s.size()|| j == t.size()){
            return max(s.size()-i,t.size()-j);
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = check(s,t,i+1,j+1);
        }else{
           dp[i][j] = 1+min(check(s,t,i+1,j+1),min(check(s,t,i,j+1),check(s,t,i+1,j)));
        }
    }
    int editDistance(string s, string t) {
        // Code here
        dp = vector<vector<int>>(s.size(), vector<int>(t.size(),-1));
        return check(s,t,0,0);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends