// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i = 0; i<n ;i++){
            st.push(i);
        }
        
        while(st.size() > 1){
          int a1 = st.top(); st.pop();
          int a2 = st.top(); st.pop();
          
          if(M[a1][a2] && !M[a2][a1]){
              st.push(a2);
          }
          if( M[a2][a1] &&  !M[a1][a2]){
              st.push(a1);
          }
        }
        if(st.empty()){ return -1; }
        
        for(int i = 0; i< n ;i++){
           if(i != st.top() && !M[i][st.top()]){
               return -1;
           } 
        }
        for(int i = 0; i< n ;i++){
           if(M[st.top()][i]){
               return -1;
           } 
        }
        return st.top();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends