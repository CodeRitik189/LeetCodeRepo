// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int i = 0;
            vector<int>v;
            
            while(i<s.size()){
                if(s[i] == '.' ){ return false; }
                if(i<s.size()-1 && s[i] == '0' && s[i+1] != '.'){ return false; }
                
                int num = 0, j = i;
                while(i<s.size() && s[i] != '.'){
                    if(!(s[i]<='9'&&s[i]>='0')){ return false;}
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                v.push_back(num);
                if(v.size()==4 && i<s.size()){return false; }
                i++;
            }
            for(int i = 0; i<4; i++){
                if(v[i]>255){
                    return false;
                }
            }
            return v.size()==4;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends