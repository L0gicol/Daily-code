#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p1 = list1, *p2 = list2, *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                tail->next = p1;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if (p1 != nullptr)
        {
            tail->next = p1;
        }
        else
        {
            tail->next = p2;
        }
        return dummy->next;
    }
};