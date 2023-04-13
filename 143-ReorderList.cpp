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
	ListNode* current = head;
	ListNode* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = last_valid;
		last_valid = current;
		current = next;
	}

	return last_valid;
}

void reorderList(ListNode* head) {
	
	if (head == nullptr) return;
	
	ListNode* end = head;
	ListNode* midpoint = head;
	ListNode* temp_placeholder = nullptr;

	while (end->next != nullptr && end->next->next != nullptr) {
		end = end->next->next;
		midpoint = midpoint->next;
	}

	if (end->next != nullptr) midpoint = midpoint->next;
	
	midpoint = Reverse_List(midpoint);

	while (head != nullptr && midpoint != nullptr) {
		end = head->next;
		temp_placeholder = midpoint->next;
		head->next = midpoint;
		midpoint->next = end;
		head = end;
		midpoint = temp_placeholder;
	}

	if (head != nullptr && head->next != nullptr) {
		head->next->next = nullptr;
	}

}
};
