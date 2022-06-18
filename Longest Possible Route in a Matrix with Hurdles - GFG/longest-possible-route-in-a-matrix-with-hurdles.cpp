// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int find(vector<vector<int>> mat, int i,int j, int& xd, int& yd){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j] == 2||mat[i][j]==0){
            return -1e5;
        }
        if(i == xd && j == yd){ return 0; }
        
        mat[i][j] = 2;
        int a1 = find(mat,i+1,j,xd,yd);
        int a2 = find(mat,i,j+1,xd,yd);
        int a3 = find(mat,i-1,j,xd,yd);
        int a4 = find(mat,i,j-1,xd,yd);
        
        return 1+max(max(a1,a2),max(a3,a4));
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        return max(find(matrix,xs,ys,xd,yd),-1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends