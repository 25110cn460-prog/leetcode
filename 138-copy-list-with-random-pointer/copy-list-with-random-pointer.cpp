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
    Node* copyll(Node*temp){
        if(temp==NULL){
            return NULL;
        }
        Node* newNode= new Node(temp->val);
        newNode->next= copyll(temp->next);
        return newNode;
    }
public:
    Node* copyRandomList(Node* head) {
       Node*head2=copyll(head);
       Node*org= head;
       Node*org1=head2;
       Node*t1=head;
       Node*t2=head2;
       int count=0;
       while(org!=NULL){
        if(org->random!=NULL){
            while(t1!=org->random){
                count++;
                t1=t1->next;
            }
            for(int i=1;i<=count;i++){
                t2=t2->next;
            }
            org1->random=t2;
        }
        t1=head;
        t2=head2;
        org=org->next;
        org1=org1->next;
        count=0;
       }
       return head2;

        
    }
};