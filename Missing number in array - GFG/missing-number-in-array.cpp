// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        for(int i =0 ; i<n-1 ;i++){
            while(arr[i] != i+1){
              if(arr[i] != n)
                swap(arr[i],arr[arr[i]-1]);
              else
                break;
            }
        }
        for(int i = 0 ; i<n-1 ;i++){
            if(arr[i] == n || arr[i] != i+1){
                return i+1;
            }
        }
        return n;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends