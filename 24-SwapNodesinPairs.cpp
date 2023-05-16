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
ListNode* swapPairs(ListNode* head) {
	
	if (head == nullptr || head->next == nullptr) return head;
	
	ListNode* last_valid = nullptr;
	ListNode* next = nullptr;
	ListNode* back = head;
	ListNode* front = head->next;

	head = head->next;

	while (front != nullptr) {

		next = front->next;

		front->next = back;

		if (last_valid != nullptr) last_valid->next = front;
		
		back->next = next;

		last_valid = back;

		if (next == nullptr) break;
		
		back = next;

		front = next->next;
	}

	return head;
}
};
