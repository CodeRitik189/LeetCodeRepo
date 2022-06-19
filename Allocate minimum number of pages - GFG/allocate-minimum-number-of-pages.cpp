// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int check(int arr[],int& n, int& m,long& mid){
   
        long sum = 0, ct = 1;
        for(int i = 0; i<n ; i++){
            if(arr[i]>mid){
                return -1;
            }
            if(sum+arr[i]>mid || m-ct == (n-i)){
                ct++;
                sum = arr[i];
            }else{
                sum += arr[i];
            }
        }
        return  m - ct;
    }
    
    long find(int arr[], int& n , int& m, long st, long ed ){
        if(st>ed){ return 1e7; }
        
        long mid = (st+ed)/2;
        
        int val = check(arr,n,m,mid);
  
        if(val>0){
            return find(arr,n,m,st,mid-1);
        }else if(val<0){
            return find(arr,n,m,mid+1,ed);
        }else{
            long ans = find(arr,n,m,st,mid-1);
            return ans < mid ? ans : mid;
        }
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        long sum = 0;
        for(int i = 0; i<N; i++){
            sum += A[i];
        }
        int ans =  find(A,N,M,1,sum);
        return ans == 1e7 ? -1 : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends