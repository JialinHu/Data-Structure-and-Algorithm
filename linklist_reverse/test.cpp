#include "node.h"

/*
struct ListNode
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

    void display();
};
*/

int main(int argc, char *argv[])
{
	int numbers[] = { 3,5 };
	int size = sizeof(numbers) / sizeof(int);
	ListNode* pRoot = constructList(size, numbers);
	ListNode* pRet = reverseBetween(pRoot, 1, 2);

	return 0;
}