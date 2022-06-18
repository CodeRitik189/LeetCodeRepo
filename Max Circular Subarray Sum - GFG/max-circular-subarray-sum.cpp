// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int mx=arr[0],omx=arr[0],mn=arr[0],omn=arr[0], sum = arr[0];
        
        for(int i = 1; i<num; i++){
            mx = max(arr[i],arr[i]+mx);
            mn = min(arr[i],arr[i]+mn);
            
            sum += arr[i];
            
            omx = max(mx,omx);
            omn = min(omn,mn);
        }
        return  sum==omn ? omx : max(omx,sum-omn);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends