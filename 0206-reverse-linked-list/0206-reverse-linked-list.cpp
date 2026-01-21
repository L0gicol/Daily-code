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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        stack <ListNode*> S;
        ListNode* p1,*p2;
        p1=head;
        while(p1){
            S.push(p1);
            p1=p1->next;
        }
        ListNode* result=S.top();
        p2=result;
        while(!S.empty()){
            p2->next=S.top();
            p2=S.top();
            S.pop();
        }
        p2->next = nullptr;
        return result;
    }
};