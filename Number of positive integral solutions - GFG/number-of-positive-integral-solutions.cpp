// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    long cal(int n, int  r){
        if(n<r){
            return 0;
        }
        long long int sum = 1, sum2 = 1;
        for(int i = n-r+1; i<= n; i++){
            sum *= i;
        }
        for(int i = 1; i<= r; i++){
            sum2 *= i;
        }
        
        return sum/sum2;
    }
    long posIntSol(string s)
    {
        int i = 0, n = s.size(), ct = 0, num = 0;
        
        while(s[i] != '='){
            if(s[i] == '+'){
                ct++;
            }
            i++;
        }
        i++;
        while(i<n){
            num = num*10+(s[i]-'0');
            i++;
        }
         return cal(num-1,ct);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends