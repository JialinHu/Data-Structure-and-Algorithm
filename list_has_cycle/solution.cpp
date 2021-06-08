#include "solution.h"


bool has_cycle_using_slow_fast_ptr(ListNode *head)
{
    if(!head)
    {
        return false;
    }

    ListNode* pSlow = head;
    ListNode* pFast = head;

    while(pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next?(pFast->next->next):(nullptr);

        if(pFast && pFast == pSlow)
        {
            return true;
        }
    }

    return false;
}

bool has_cycle_using_map(ListNode *head)
{
    std::map<ListNode*, int> savedNode;

    while(head)
    {
        if(savedNode.find(head) != savedNode.end())
        {
            return true;
        }
        head = head->next;
    }

    return false;
}