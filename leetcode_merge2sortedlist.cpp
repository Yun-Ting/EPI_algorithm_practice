#include <iostream>
#include <string>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy_head(0);
    ListNode* tail = &dummy_head;
    
    while(l1 && l2) {
        if ( l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy_head.next;
    
}

int main() {
    
    // case1
    ListNode* mylist1 = new ListNode(1);
    mylist1->next = new ListNode(3);
    mylist1->next->next = new ListNode(5);
    
    ListNode* mylist2 = new ListNode(2);
    mylist2->next = new ListNode(3);
    mylist2->next->next = new ListNode(7);
    mylist2->next->next->next = new ListNode(9);
    
    // case2
    ListNode* mylist3 = new ListNode(1);
    mylist3->next = new ListNode(2);
    mylist3->next->next = new ListNode(3);
    
    ListNode* mylist4 = new ListNode(4);
    mylist4->next = new ListNode(5);
    
    ListNode* result1 = mergeTwoLists(mylist1, mylist2);
    ListNode* result2 = mergeTwoLists(mylist3, mylist4);
    while(result1) {
        cout << result1->val << endl;
        result1 = result1->next;
    }
    while(result2) {
        cout << result2->val << endl;
        result2 = result2->next;
    }
    return 0;
}
