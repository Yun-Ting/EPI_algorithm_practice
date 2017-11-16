struct ListNode {
	ListNode(int x) : val(x), next(nullptr) {}
	int val;
	ListNode* next;
};


ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2) {
	ListNode dummy = ListNode(0);
	ListNode* tail = &dummy;

	while (l1 && l2) {
		AppendNode(l1->val <= l2->val ? l1 : l2, tail);
	}

	// Appends the remaining nodes of l1 or l2
	tail->next = l1 ? l1 : l2;
	return dummy->next;
}

void AppendNode(ListNode* node, ListNode* tail) {
	tail->next = node;
	tail = node;
	node = node->next;
}