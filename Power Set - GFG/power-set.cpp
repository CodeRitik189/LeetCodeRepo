// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    int num = pow(2,s.size())-1;
		    
		    for(int nm = 1; nm<=num ; nm++){
		        string t = "";
		        for(int i=0;i<s.size();i++){
		            if(nm&(1<<i)){
		               t += s[i]; 
		            }
		        }
		        ans.push_back(t);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends