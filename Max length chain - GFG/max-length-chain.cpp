// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

static bool cmp( struct val v1,struct val v2){
    return v1.second<v2.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here

    sort(p,p+n,cmp);
    
    vector<int>dp(n,1);
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(p[i].first > p[j].second){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    
    int maxi = 0;
    for(int i = 0; i<n ; i++){
      maxi = max(maxi,dp[i]);
    }
    return maxi;
}