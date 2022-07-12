// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        stack<pair<int,int>>st;
        
        for(int i = 0; i<N; i++){
            if(st.empty()||st.top().first>A[i]){
                st.push({A[i],i});
            }
        }
        
        int prev = A[N-1]-1, ans = 0;
        for(int i = N-1; i >= 0; i--){
            if(A[i] <= prev)continue;
            while(!st.empty() && st.top().second>=i){
                st.pop();
            }
            if(st.empty()){
               return ans;
            }else{
               while(!st.empty()&&st.top().first<=A[i]){
                   ans = max(ans,i-st.top().second);
                   st.pop();
               }
            }
            prev = A[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends