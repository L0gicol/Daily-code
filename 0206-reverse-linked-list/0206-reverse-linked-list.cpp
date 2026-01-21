class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL) return NULL;
        ListNode* curr=head,*prev,*temp;
        prev=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};