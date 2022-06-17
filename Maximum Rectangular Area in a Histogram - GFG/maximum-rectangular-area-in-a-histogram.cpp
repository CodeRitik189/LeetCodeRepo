// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
       long long int ans = 0 ;
        stack<int>st;
        
        for(int i=0 ; i<=n ; i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int temp = st.top();
                st.pop();
                
               long long int ht = heights[temp];
               long long int wt = !st.empty() ? i - st.top()-1 : i;
                
                ans = max(ans,wt*ht);
            }
            st.push(i);
        }

        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends