// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
       long long int s = 0, s2 = 0 ;
        
        for(int i = 0; i<n ;i++){
            s += (long long int)arr[i];
            s2 += (long long int)arr[i]*arr[i];
        }
        
        long long int d1 = s-((long long int)n*(n+1))/2;
        long long int d2 = (s2 - ((long long int)n*(n+1)*(2*n+1))/6)/d1;
        
        int* ans = new int[2];
        
        ans[0] = abs(d1+d2)/2;
        ans[1] = abs(d1-d2)/2;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends