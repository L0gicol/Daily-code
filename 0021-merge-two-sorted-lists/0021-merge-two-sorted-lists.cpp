class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1,*p2=list2;
        ListNode *head=new ListNode(NULL,nullptr);
        ListNode *p3=head;
        while(p1&&p2){
            p3->next=new ListNode();
            p3=p3->next;
            if(p1->val>p2->val){
                p3->val=p2->val;
                p2=p2->next;
            }
            else{
                p3->val=p1->val;
                p1=p1->next;
            }
        }
        while(p1){
            p3->next=new ListNode();
            p3=p3->next;
            p3->val=p1->val;
            p1=p1->next;
        }
        while(p2){
            p3->next=new ListNode();
            p3=p3->next;
            p3->val=p2->val;
            p2=p2->next;
        }
        return head->next;
    }
};