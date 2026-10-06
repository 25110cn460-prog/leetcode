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
ListNode* call(ListNode*temp1, ListNode* temp2, int carry){
    int add1;
    int add2;
    int digit;
    int sum;
    if(temp1==nullptr&& temp2==nullptr){
        if(carry==0){
            return nullptr;
        }
        ListNode* newnode= new ListNode(carry);
        return newnode;
    }
    else if(temp1==nullptr){
        add1=0;
        add2=temp2->val;
        sum= add1+ add2+ carry;
        digit=sum%10;
        carry=sum/10;
        ListNode *newnode= new ListNode(digit);
        newnode->next=call(temp1, temp2->next, carry);
        return newnode;
    }
    else if(temp2==nullptr){
        add1=0;
        add2=temp1->val;
        sum= add1+ add2+ carry;
        digit= sum%10;
        carry= sum/10;
        ListNode* newnode=  new ListNode(digit);
        newnode->next= call(temp1->next, temp2, carry);
        return newnode;
    }
    else{
        add1= temp1->val;
        add2=temp2->val;
        sum = add1+ add2+ carry;
        digit= sum%10;
        carry=sum/10;
        ListNode*newnode= new ListNode(digit);
        newnode->next=call(temp1->next, temp2->next, carry);
        return newnode;
    }
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return call(l1,l2,0);
        
    }
};