// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
     vector<vector<int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i],dep[i]});
        }
        
        sort(v.begin(),v.end());
        
        multiset<int>s;
        int ans = 0;
        
        for(int i=0 ; i<n ; i++){
            if(s.size()==0||*s.begin()>=v[i][0]){
                s.insert(v[i][1]);
            }else{
                while(!s.empty()&&*s.begin()<v[i][0]){
                    s.erase(s.begin());
                }
                s.insert(v[i][1]);
            }
            if(ans<s.size()){ ans = s.size(); }
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends