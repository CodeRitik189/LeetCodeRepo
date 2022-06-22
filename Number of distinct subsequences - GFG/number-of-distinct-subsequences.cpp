// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public :	
  
	int distinctSubsequences(string s)
	{
	       int n = s.size();
	    // Your code goes here
	    vector<long long int>dp(n+1,1);
	    vector<int>last(26,-1);
	    
	    dp[0] = 1;
	    
	    for(int i = 1; i<= n; i++){
	        dp[i] = 2*dp[i-1];
	        
	        if(last[s[i-1]-'a'] != -1){
	            dp[i] -= dp[last[s[i-1]-'a']];
	        }
	        last[s[i-1]-'a'] = i-1;
	    }
	    return dp[n]%1000000007;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends