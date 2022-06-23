// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<long>fact;
	int nm = 1000000007;
	long check(int N){
	    if(N<=0){ return 1;}
	    
	    if(fact[N] != -1){ return fact[N]; }
	    return fact[N] = (check(N-1)+check(N-2))%nm;
	}
	int TotalWays(int N)
	{
	    // Code here
	    fact = vector<long>(N+1,-1);
	    long ans = check(N);
	    return (ans*ans)%nm;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends