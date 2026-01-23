#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast, *slow;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        fast = dummy->next;
        slow = dummy;
        while (1)
        {
            if (fast == slow)
            {
                return true;
            }
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};