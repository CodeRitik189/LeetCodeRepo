// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        int j = 0;
        
        while(j<n && arr[j]<k){
            j++;
        }
        
        for(int i = max(0,j-1) ; i<n-1 ; i++){
           int diff = abs(min(arr[0]+k,arr[i+1]-k)- max(arr[i]+k,arr[n-1]-k));
           ans = min(ans,diff);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends