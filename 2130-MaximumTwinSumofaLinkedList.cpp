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

	ListNode* forward = nullptr;
	ListNode* backward = nullptr;

	while (head != nullptr) {
		forward = head->next;
		head->next = backward;
		backward = head;
		head = forward;
	}
	return backward;
}

int pairSum(ListNode* head) {

	ListNode* mid = head;
	ListNode* end = head->next;
	ListNode* next = nullptr;
	int max_pair = 0;

	while (end != nullptr && end->next != nullptr) {
		mid = mid->next;
		end = end->next->next;
	}
	
	next = mid->next;
	mid->next = nullptr;

	head = Reverse_List(head);

	while (head != nullptr && next != nullptr) {
		max_pair = (max_pair > head->val + next->val) ? max_pair : head->val + next->val;
		head = head->next;
		next = next->next;
	}
	
	return max_pair;
}
};
