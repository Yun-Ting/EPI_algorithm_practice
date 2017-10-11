// 8.5_search-a-posting-list.cpp

// Recursive
// n is the number of tree nodes
// Time Comp: O(n)
// Space Comp: O(n) -> maximum function call stack of O(n)
// worst case: every node's jump node and the next node are equal
void setJumpOrder(const ListNode* l) {
	setJumpOrderHelper(l, new int(0));
}

void setJumpOrderHelper(const ListNode* l, int* order) {
	if (l && l->order == -1) {
		l->order = (*order)++;
		setJumpOrderHelper(l->jump, order);
		setJumpOrderHelper(l->next, order);
	}
}

// Iterative
// Time Comp: O(n)
// Space Comp: O(n) (the stack)
void setJumpOrder(const ListNode* l) {
	stack<ListNode*> s;
	int order = 0;
	while (!s.empty()) {
		ListNode* cur = s.top();
		s.pop();
		if (cur && cur->order == -1) {
			cur->order = order++;
			s.emplace(cur->next);
			s.emplace(cur->jump);
		}
	}
}