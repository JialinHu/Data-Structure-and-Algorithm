#include "solution.h"


bool has_cycle_using_slow_fast_ptr(ListNode *head)
{
    if (!head)
    {
        return false;
    }

    ListNode* pSlow = head;
    ListNode* pFast = head;

    while (pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next?(pFast->next->next):(nullptr);

        if (pFast && pFast == pSlow)
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
        if (savedNode.end() != savedNode.find(head))
        {
            return true;
        }
        savedNode.insert(std::make_pair(head, head->val));
        head = head->next;
    }

    return false;
}

bool has_cycle_by_redirect_next_to_self(ListNode* head)
{
    ListNode* pPre = head;
    ListNode* pCur = pPre;

    while (pCur)
    {
        if (pCur == pCur->next)
        {
            return true;
        }
        pPre = pCur;
        pCur = pCur->next;

        pPre->next = pPre;
    }

    return false;
}