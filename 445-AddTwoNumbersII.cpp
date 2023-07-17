/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* Reverse_List(ListNode* head) {

	ListNode* last_valid = nullptr;
	ListNode* next_node = nullptr;

	while (head != nullptr) {

		next_node = head->next;
		head->next = last_valid;
		last_valid = head;
		head = next_node;
	}
	return last_valid;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* l1_rev = Reverse_List(l1);
	ListNode* l2_rev = Reverse_List(l2);
	ListNode* head = l1_rev;
	ListNode* last_valid = nullptr;
	int carry = 0;

	while (l1_rev != nullptr && l2_rev != nullptr) {
		l1_rev->val += l2_rev->val + carry;
		carry = (l1_rev->val > 9) ? 1 : 0;
		l1_rev->val %= 10;
		last_valid = l1_rev;
		l1_rev = l1_rev->next;
		l2_rev = l2_rev->next;
	}

	

	if (l1_rev == nullptr && l2_rev != nullptr) {
		last_valid->next = l2_rev;
		l1_rev = l2_rev;
	}

	while (l1_rev != nullptr) {

		l1_rev->val += carry;
		carry = (l1_rev->val > 9) ? 1 : 0;
		l1_rev->val %= 10;
		last_valid = l1_rev;
		l1_rev = l1_rev->next;

	}

	if (carry) {
		last_valid->next = new ListNode(carry);
	}

	l1_rev = Reverse_List(head);

	return l1_rev;
}
};
