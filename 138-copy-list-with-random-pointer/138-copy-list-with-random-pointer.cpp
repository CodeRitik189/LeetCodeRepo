/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){return head;}
        Node* temp = head;
        while(temp){
            Node* nm = new Node(temp->val);
            Node* t = temp -> next;
            temp->next = nm;
            nm -> next = t;
            temp = t;
        }
        
        temp = head;
        
        while(temp){
            temp -> next -> random = temp -> random ? temp->random->next:NULL;
            temp = temp -> next -> next;
        }
        
        temp = head;
        Node* ans = head -> next;
        Node* headn = head->next;
        
        while(ans){
           temp->next = ans->next;
           if(ans->next)ans->next = ans->next->next;
           
           ans = ans->next;
           temp = temp->next;
        }
        return headn;
    }
};