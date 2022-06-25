// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node* rev(Node* head){
    if(!head || !head->next){ return head; }
    
    Node* nhead = rev(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return nhead;
}

void reorderList(Node* head) {
    
    if(!head || !head->next || !head->next->next){
        return;
    }
    // Your code here
    Node* t1 = head; 
    Node* t2 = head->next;
    
    while(t2 && t2->next){
        t2 = t2->next->next;
        t1 = t1->next;
    }
    Node* nhead = t1->next;
    t1->next = NULL;
    
    t2 = rev(nhead);
    t1 = head->next;
    nhead = head;
    nhead->next = NULL;
    
    while(t1 && t2){
       Node* temp1 = t1->next;
       Node* temp2 = t2->next;
       nhead->next = t2;
       t2->next = t1;
       t1->next = NULL;
       nhead = t1; 
       t1 = temp1;
       t2 = temp2;
    }
    if(t2){
        nhead->next = t2;
    }
    if(t1){
        nhead->next = t1;
    }
}