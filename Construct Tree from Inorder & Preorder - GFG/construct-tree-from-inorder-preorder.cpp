// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int>um;
    Node* find(int in[], int pre[], int pst, int ped, int ist, int ied){
        if(pst>ped){
            return NULL;
        }
        Node* root = new Node(pre[pst]);
        
        int rt = um[pre[pst]];
        
        root->left = find(in,pre,pst+1,pst+(rt-ist),ist,rt-1);
        root->right = find(in,pre,pst+1+(rt-ist),ped,rt+1,ied);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        for(int i = 0; i<n; i++){
            um[in[i]] = i;
        }
        return find(in,pre,0,n-1,0,n-1);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends