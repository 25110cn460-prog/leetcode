/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* hello(Node* temp){
        Node*after;
        Node*end;
        while(temp!=NULL){
            after= temp->next;
            if(temp->child!=NULL){
                end= hello(temp->child);
                temp->next=temp->child;
                temp->child->prev=temp;
                temp->child= NULL;
                end->next=after;
                if(after!=NULL){
                    after->prev=end;
                }
                else{
                    return end;
                }
            }
            if(after==NULL){
                return temp;
            }
            temp=after;
        }
        return NULL;
    }
    Node* flatten(Node* head) {
        hello(head);
        return head;
        
    }
}; 