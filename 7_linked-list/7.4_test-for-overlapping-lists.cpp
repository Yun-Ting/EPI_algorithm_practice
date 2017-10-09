// 7.4_test-for-overlapping-lists.cpp

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* OverlappingNoCycleLists( ListNode* l1, ListNode* l2) {
	int l1_len = Length(l1);
	int l2_len = Length(l2);

	// Advances the longer list to get equal length lists.
	AdvancedListByK( abs(l2_len - l1_len), l1_len > l2_len ? &l1 : &l2 );

	while (l1 && l2 && l1 != l2) {
		l1 = l1->next;
		l2 = l2->next;
	}
}

int Length(ListNode* l) {
	int length = 0;
	while (l) {
		++length;
		l = l->next;
	}
	return length;
}

// Advances L by k steps
void AdvancedListByK(int k, ListNode* L) {
	while (k--) {
		L = L->next;
	}
}