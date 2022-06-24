// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool  find(int level, long pos, char ch){
        if(pos == 1){ return ch == 'e'; }
        if(pos %2 == 0 ){
            return ch=='d' ? find(level-1,(pos+1)/2 ,'e') : find(level-1, (pos+1)/2,'d');
        }
        return find(level-1,(pos+1)/2 ,ch); 
    }
    char profession(int level, int pos){
        // code here
        if(find(level,long(pos),'d')){
            return 'd';
        }else{
            return 'e';
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends