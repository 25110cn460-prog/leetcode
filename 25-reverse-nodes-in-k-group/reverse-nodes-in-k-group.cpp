/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode* call(ListNode*head,int k){
    ListNode*temp=head;
    ListNode*temp1=head;
    ListNode*end;
    ListNode*varr;
    for(int i=1;i<k;i++){
        if(temp==nullptr){
            return head;
        }
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    else{
     end= call(temp->next, k);
     }
    for(int i=0;i<k;i++){
        varr=temp1->next;
        temp1->next=end;
        end=temp1;
        temp1=varr;
    }
    return end;

   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return call(head,k);
        

    }
};