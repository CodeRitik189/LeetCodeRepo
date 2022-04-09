// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    // int check(int* a , int idx ,int ct, int n){
    //     if(idx==n){
    //         return 0;
    //     }
    //     if(a[idx]==ct){
    //         return check(a, idx+1, ct, n);
    //     }else{
    //         return 1+check(a,idx+1,1-ct,n);
    //     }
    // }
    int countFlips(int a[],int n)
    {
        //return check(a, 0 ,1 ,n );//code here.
        int ct = 1,ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(ct!=a[i]){
                ans++;
                ct = 1-ct;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout<<ob.countFlips(a,n)<<endl;
    }
    return 0;
}

  // } Driver Code Ends