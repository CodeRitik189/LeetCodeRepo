// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    vector<vector<int>>dp;
    bool check(string& a,string& b,string& c,int i,int j,int k){
        if(k==c.size()){
            return (i==a.size() && j==b.size());
        }
        if(i==a.size()){
            return b[j]==c[k] && check(a,b,c,i,j+1,k+1);
        }
        if(j==b.size()){
            return a[i]==c[k] && check(a,b,c,i+1,j,k+1);
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(a[i]==c[k] && check(a,b,c,i+1,j,k+1)){
            return dp[i][j] = true;
        }
        if(b[j]==c[k] && check(a,b,c,i,j+1,k+1)){
            return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        dp = vector<vector<int>>(A.size(),vector<int>(B.size(),-1));
        return A.size()+B.size() == C.size() && check(A,B,C,0,0,0);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends