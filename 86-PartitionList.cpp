class Solution {
public:
ListNode* partition(ListNode* head, int x) {

	ListNode* smaller_nodes = nullptr;
	ListNode* larger_nodes = nullptr;
	ListNode* new_head = nullptr;
	ListNode* first_larger_node = nullptr;
	ListNode* Current = head;

	while (Current != nullptr) {
		if (Current->val < x) {
			if (new_head == nullptr) {
				new_head = Current;
				smaller_nodes = Current;
			}
			else {
				smaller_nodes->next = Current;
				smaller_nodes = smaller_nodes->next;
			}
		}
		else {
			if (first_larger_node == nullptr) {
				first_larger_node = Current;
				larger_nodes = Current;
			}
			else {
				larger_nodes->next = Current;
				larger_nodes = larger_nodes->next;
			}
		}
		Current = Current->next;
	}

	if (new_head == nullptr || first_larger_node == nullptr) return head;
	
	larger_nodes->next = nullptr;

	smaller_nodes->next = first_larger_node;

	return new_head;
}
};
