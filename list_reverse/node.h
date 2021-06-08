#pragma once
#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

    void display();
};

ListNode* constructList(int size, int* numbers);

ListNode* reverseList(ListNode* head, ListNode* right = nullptr);

ListNode* reverseBetween(ListNode* head, int left, int right);