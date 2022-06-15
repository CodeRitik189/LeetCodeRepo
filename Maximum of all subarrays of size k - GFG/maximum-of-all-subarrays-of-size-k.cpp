// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i = 0;
        deque<pair<int,int>>dq;
        vector<int>ans;
        
        while(i<k-1){
           while(!dq.empty() && dq.back().first<=arr[i]){
               dq.pop_back();
           } 
           dq.push_back({arr[i],i});
           i++;
        }
        
        for(int i = 0 ; i<= n-k ; i++){
           while(!dq.empty() && dq.back().first<=arr[i+k-1]){
               dq.pop_back();
           } 
           dq.push_back({arr[i+k-1],i+k-1});
           while(!dq.empty() && dq.front().second<i){
               dq.pop_front();
           } 
           ans.push_back(dq.front().first);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends