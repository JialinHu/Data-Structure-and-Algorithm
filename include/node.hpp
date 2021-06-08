

struct ListNode
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

    void display();
};

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