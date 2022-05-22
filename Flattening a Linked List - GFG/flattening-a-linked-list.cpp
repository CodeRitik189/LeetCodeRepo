// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeTwoLists(Node* list1, Node* list2) {
        // could have replaced one list to a complete sorted 
        Node* t1 = list1;
        Node* t2 = list2;
        Node* head=NULL;
        Node* temp=NULL;
        while(list1&&list2){
           if(list1->data<list2->data){
               if(!head){
                   head = new Node(list1->data);
                   temp = head;
               }else{
                   temp->bottom = new Node(list1->data);
                   temp = temp->bottom;
               }
               list1 = list1->bottom;
           }else{
               if(!head){
                   head = new Node(list2->data);
                   temp = head;
               }else{
                   temp->bottom = new Node(list2->data);
                   temp = temp->bottom;
               }
               list2 = list2->bottom;
           } 
        }
        if(list1){
           if(!head) return list1;
            temp->bottom = list1;
        }else{
            if(!head) return list2;
            temp->bottom = list2;
        }
        return head;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(!root||!root->next){
       return root;
   }
   root->next = flatten(root->next);
  return mergeTwoLists(root,root->next);
}

