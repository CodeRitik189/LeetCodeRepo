// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>v(26,0);
		    
		    int j = 0, n = A.size();
		    string ans = "";
		    ans += A[0];
		    v[A[0]-'a']++;
		    
		    for(int i = 1; i<n ; i++){
		        v[A[i]-'a']++;
		        while(v[A[j]-'a']>1 && j<=i){
		            j++;
		        }
		        if(j>i){
		            ans += '#';
		        }else{
		            ans += A[j];
		        }
		    }
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends