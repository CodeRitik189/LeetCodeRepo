// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
   // use gap algo
   
	void merge(int ar1[], int ar2[], int m, int n) {
           int gap = ((m+n)%2==0 ? (m+n) : (m+n+1))/2;
           
           while( gap != 0){
               int i = 0, j = i+gap;
               while( j < m+n ){
                   
                   if(j >= m && i>= m){
                       if(ar2[i-m]>ar2[j-m]){  swap(ar2[i-m],ar2[j-m]);  }
                   }else if( j >= m){
                        if(ar1[i]>ar2[j-m]){  swap(ar1[i],ar2[j-m]);  }
                   }else{
                       if(ar1[i]>ar1[j]){  swap(ar1[i],ar1[j]);  }
                   }
                   i++;
                   j++;
               }
               gap = (gap%2== 0||gap==1) ? gap/2 : (gap+1)/2;
           }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends