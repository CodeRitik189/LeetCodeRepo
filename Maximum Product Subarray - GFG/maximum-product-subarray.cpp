// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mn = arr[0],mx = arr[0], ans = arr[0];
	    
	    for(int i= 1; i<n ;i++){

	        if(arr[i]<0){
	            swap(mx,mn);
	        }
	        mx = arr[i] > mx*arr[i] ? arr[i] : mx* arr[i];
	        mn = arr[i] < mn*arr[i] ? arr[i] : mn* arr[i];
	        
	        ans = max(ans,mx);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends