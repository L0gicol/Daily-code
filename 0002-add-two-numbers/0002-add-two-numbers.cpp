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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up=0;
        ListNode* temp1=l1,*temp2=l2,*temp3;
        ListNode* head=new ListNode();
        temp3=head;
        while(temp1!=NULL&&temp2!=NULL){
            ListNode* newnode=new ListNode();
            temp3->next=newnode;
            temp3=newnode;
            if(up){
                temp3->val+=1;
            }
            up=0;
            if(temp1->val+temp2->val+temp3->val>=10){
                up=1;
            }
            temp3->val=(temp1->val+temp2->val+temp3->val)%10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            ListNode* newnode=new ListNode();
            temp3->next=newnode;
            temp3=newnode;
            if(up){
                temp3->val+=1;
            }
            up=0;
            if(temp1->val+temp3->val>=10){
                up=1;
            }
            temp3->val=(temp1->val+temp3->val)%10;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            ListNode* newnode=new ListNode();
            temp3->next=newnode;
            temp3=newnode;
            if(up){
                temp3->val+=1;
            }
            up=0;
            if(temp2->val+temp3->val>=10){
                up=1;
            }
            temp3->val=(temp2->val+temp3->val)%10;
            temp2=temp2->next;
        }
        if(up){
            ListNode* newnode=new ListNode();
            temp3->next=newnode;
            temp3=temp3->next;
            temp3->val=1;
            
        }
        return head->next;
    }
};