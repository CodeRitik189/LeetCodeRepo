// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    Node* rev(Node* head){
        if(!head || !head->next){ return head; }
        
        Node* nhead = rev(head->next);
        head->next->next = head;
        head ->next = NULL;
        
        return nhead;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node* t = head;
        Node* p = head;
        Node* pp = NULL;
        
        int k = n-m;
        while(k--){
            t = t->next;
        }
        
        k = 1;
        
        while(k<m){
            pp = p;
            p = p->next;
            t = t->next;
            k++;
        }
        Node* temp = t->next;
        t->next = NULL;
        
        if(pp){
          pp->next = rev(p);
        }else{
          head = rev(p);
        }
        p ->next = temp;
        
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends