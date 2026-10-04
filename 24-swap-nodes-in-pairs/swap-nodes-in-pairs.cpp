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
    ListNode* hello(ListNode*head){
        ListNode* temp=head;
        ListNode* temp2= head;
        ListNode*end;
        ListNode*varr;
        for(int i=1;i<2;i++){
            if(temp==nullptr){
                return head;
            }
            temp=temp->next;
        }
        if(temp==nullptr){
            return head;
        }
        else{
           end=hello(temp->next);
        }
        varr=temp2->next;
        temp2->next=end;
        varr->next=temp2;
        return varr;

    }
    ListNode* swapPairs(ListNode* head) {
        
      return hello(head);

    }
};