// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int multi(double mid, int i, double magnets[], int n){
        double a1 = 0.0, a2 = 0.0;
        
        int j = 0;
        while(j<i){ a1 += 1/(mid-magnets[j++]); }
        while(j<n){ a2 += 1/(magnets[j++]-mid); }
        
        if(a1 == a2 || abs(a1-a2)< 0.000001){
            return 0;
        }else if(a1<a2){
            return 1;
        }else{
            return -1;
        }
    }
      
     void nullPoints(int n, double magnets[], double getAnswer[])
     {
        // Your code goes here   
        int k = 0;

        for(int i = 1; i<n ;i++){
             double low = magnets[i-1], high = magnets[i];

             while((high-low)>=0.0000001){
               double mid = (low+high)/2.0;
               int val = multi(mid,i,magnets,n);
               if(val==-1){
                 low = mid;
               }else if(val==1){
                high = mid;
               }else{
                  getAnswer[k++] = mid;
                  break;
               }
             }
        }
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends