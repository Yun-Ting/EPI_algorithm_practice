// 13.10_implement-a-fast-sorting-algorithm-for-lists.cpp

// sol-1
struct ListNode {
	ListNode(int x) : data(x), next(nullptr){};
	
	int data;
	ListNode* next;
};

ListNode* InsertionSort(const ListNode* L) {
	auto dummy_head = ListNode(0);
	auto iter = L;

	// Invariant:
	// the sublist consisting of nodes up to and including
	// iter is sorted in increasing order. 
	// We need to ensure that after we move to iter->next this property continues to hold.
	// We do this by swapping iter->next with its predecessors in the list
	// till it's in the right place
	while (iter && iter->next) {
		if (iter->data > iter->next->data) {
			auto target = iter->next;
			auto pre = dummy_head;
			while (pre->next->val < target->val) {
				pre = pre->next;
			}
			auto tmp = pre->next;
			pre->next = target;
			iter->next = target->next;
			target->next = tmp;
		} else {
			iter = iter->next;
		}
	}
	return dummy_head->next;
}

// sol-2
ListNode* StableSortList(ListNode* L) {
	// Base cases: L is empty or a single node, nothing to do.
	if (L == nullptr || L->next == nullptr) {
		return L;
	}

	// Find the midpoint of L using a slow and fast pointer
	ListNode* slow = L;
	ListNode* pre_slow = slow;
	ListNode* fast = L;
	while (fast && fast->next) {
		pre_slow = slow;
		fast = fast->next->next;
		slow = slow->next;
	}

	pre_slow->next = nullptr;
	return MergeTwoSOrtedLists(StableSortList(L), StableSortList(slow));
}








ListNode* InsertionSort(ListNode* L) {
	ListNode dummy = ListNode(0);
	ListNode* dummy_ptr = &dummy;
	ListNode* iter = L;

	while (iter && iter->next) {
		if (iter->data > iter->next->val) {
			auto target = iter->next;
			auto pre = dummy_ptr;
			while (pre->next->data < target->data) {
				pre = pre->next;
			}
			auto tmp = pre->next;
			pre->next = target;
			iter->next = target->next;
			target->next = tmp;
		} else {
			iter = iter->next;
		}
	}
	return dummy.next;
}







