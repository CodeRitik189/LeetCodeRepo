// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
        int fd(int nm ){
            int ct = 0, j = 5;
            while(nm/j != 0){
                ct += nm/j;
                j *= 5;
            }
            return ct;
        }
        
        int find(int st, int ed, int& n){
            if(st > ed){ return 1e5; }
            int mid = (st+ed)/2;
            
            if(fd(mid)>=n){
               return min(mid,find(st,mid-1,n)); 
            }else{
                return find(mid+1,ed,n);
            }
        }
        int findNum(int n)
        {
        //complete the function here
          return find(5,n*5,n);
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends