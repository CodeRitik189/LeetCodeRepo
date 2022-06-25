// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    int check(string& s, int idx, string str, unordered_map<string,int>& um){
        if(idx == s.size()){
            return um.find(str) != um.end();
        }
        
    return (um.find(str+s[idx])!=um.end()&&check(s,idx+1,"",um))||check(s,idx+1,str+s[idx],um);
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>um;
        for(int i = 0; i<B.size(); i++){
            um[B[i]]++;
        }
        
        return check(A,0,"",um);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends