#include "node.h"

void ListNode::display()
{
    ListNode* pTmp = this;

    std::cout << "ListNode:" << std::endl;

    while (pTmp)
    {
        std::cout << pTmp->val << "->";
        pTmp = pTmp->next;
    }

    std::cout << "nullptr" << std::endl;
}

ListNode* constructList(int size, int* numbers)
{
    ListNode* pRoot = nullptr;
    if (size > 0)
    {
        pRoot = new ListNode(numbers[0]);

        ListNode* pTmp = nullptr;
        ListNode* pCur = pRoot;

        for (int i = 1; i < size; ++i)
        {
            pTmp = new ListNode(numbers[i]);
            pCur->next = pTmp;

            pCur = pCur->next;
        }
    }

    return pRoot;
}

ListNode* reverseList(ListNode* head, ListNode* right)
{
    ListNode* pPre = head;
    ListNode* pCur = pPre->next;

    if (pCur)
    {
        pPre->next = right;
    }

    ListNode* pNext = nullptr;
    while (pCur)
    {
        pNext = pCur->next;
        pCur->next = pPre;

        pPre = pCur;
        pCur = pNext;
    }

    std::cout << "Event: reverse completed, use list->display() to see the result:" << std::endl;
    pPre->display();

    return pPre;
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (!head)
    {
        std::cout << "Error: the 'head' is nullptr." << std::endl;
        return nullptr;
    }

    if (right > left)
    {
        ListNode* pLeft = nullptr;
        ListNode* pRoot = head;
        if (left > 1)
        {
            pLeft = head;
            for (int i = 1; i < left - 1; ++i)
            {
                if (pLeft == nullptr)
                {
                    return pLeft;
                }
                pLeft = pLeft->next;
            }
        }

        ListNode* pRight = head;
        for (int j = 0; j < right - 1; ++j)
        {
            if (pRight == nullptr)
            {
                return pRight;
            }
            pRight = pRight->next;
        }
        ListNode* pTmp = nullptr;
        if (pRight)
        {
            pTmp = pRight->next;
            pRight->next = nullptr;
            pRight = pTmp;
        }

        ListNode* pMid = nullptr;
        if (pLeft)
        {
            pMid = pLeft->next;
            pLeft->next = nullptr;
        }
        else
        {
            pMid = pRoot;
        }
        /*
        * origin:  1 -> 2 -> 3 -> 4-> nullptr
        *          ^
        *          |
        *         pMid
        *
        * after:   4 -> 3 -> 2 -> 1 -> pRight(by default, nullptr)
        *          ^              ^
        *          |              |
        *         pPre           pMid
        */
        ListNode* pPre = reverseList(pMid, pRight);

        if (pLeft)
        {
            pLeft->next = pPre;
        }
        else
        {
            pRoot = pPre;
        }
        std::cout << "Event: add other node completed, use list->display() to see the result:" << std::endl;
        pRoot->display();
        return pRoot;
    }
    else if (right == left)
    {
        std::cout << "Warning: The 'right' equals to the 'left', return the List itself." << std::endl;
        return head;
    }
    else
    {
        std::cout << "Error: the 'right' is smaller than the 'left', can't reverse the List." << std::endl;
        return nullptr;
    }
}