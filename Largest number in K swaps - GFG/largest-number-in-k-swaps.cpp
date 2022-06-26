// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans = "";
    void check(string& s, int idx, int k){
        if(k==0 || idx == s.size()){ 
            if(ans<s){
                ans = s;
            }
            return;
        }
        
        for(int i = idx; i<s.size(); i++){
           if(s[idx]<=s[i]){
             swap(s[idx],s[i]);
             check(s,idx+1,i!=idx ? k-1 : k);
             swap(s[idx],s[i]);
           }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       ans = str;
       check(str,0,k);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends