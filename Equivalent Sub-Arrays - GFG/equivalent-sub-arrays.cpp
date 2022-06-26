// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>um;
        unordered_map<int,int>um2;
        int dc = 0;
        
        for(int i =0 ; i<n; i++){
            um[arr[i]]++;
        }
        
        int i = 0, j = 0, ans = 0;
        
        while(i<n){
            um2[arr[i]]++;
            if(um2[arr[i]] == 1){ dc++; }
            
            if(dc == um.size()){
                while(dc==um.size()){
                    ans += (n-i);
                    um2[arr[j]]--;
                    if(um2[arr[j]] == 0){dc--; }
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends