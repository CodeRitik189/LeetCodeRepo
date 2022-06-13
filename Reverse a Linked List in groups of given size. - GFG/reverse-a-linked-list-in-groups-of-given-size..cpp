// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node* rev(struct node *head){
        if((!head) || !head ->next ){
            return head;
        }
        struct node* nhead = rev(head->next);
        head->next->next = head;
        head -> next = NULL;
        return nhead;
    }
    struct node *reverse (struct node *head, int k)
    { 
      //  Complete this method
        if(!head || !head ->next ){
            return head;
        }
        struct node* t = head;
        
        int j = k;
        
        while(t && j>1){
            t = t->next;
            j--;
        }
        
        if(t && t->next ){
            struct node* tp = t->next;
            t -> next = NULL;
            struct node* nhead = rev(head);
            head -> next = reverse(tp, k);
            return nhead;
        }else{
            return rev(head);
        }
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends