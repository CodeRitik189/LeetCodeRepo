// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int m, int n) 
        { 
            // code here 
            int gap = (n+m+1)/2;
            
            while(gap != 0){
                int i = 0, j = i+gap;
                
                while(j<m+n){
                    if(i<m && j<m){
                        if(arr1[i]>arr1[j]){
                            swap(arr1[i],arr1[j]);
                        }
                    }else if(i >= m){
                        if(arr2[i-m]>arr2[j-m]){
                            swap(arr2[i-m],arr2[j-m]);
                        }
                    }else{
                        if(arr1[i]>arr2[j-m]){
                            swap(arr1[i],arr2[j-m]);
                        }
                    }
                    i++;
                    j++;
                }
                if(gap == 1)
                   gap = 0 ;
                 else
                   gap = gap/2 + gap%2;
                   
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends