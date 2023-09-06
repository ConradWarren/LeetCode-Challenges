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
std::vector<ListNode*> splitListToParts(ListNode* head, int k) {

	ListNode* current = head;
	ListNode* last_valid = nullptr;
	int length = 0;
	int target = 0;
	int offset = 0;
	int idx = 0;
	std::vector<ListNode*> result(k, nullptr);

	while (current != nullptr){
		length++;
		current = current->next;
	}
	
	target = length / k;
	offset = length % k;
	current = head;

	for (int i = 0; i < k; i++) {

		result[i] = current;
		if (last_valid != nullptr) last_valid->next = nullptr;
		idx = 0;

		while (current != nullptr && idx < (target + ((offset) ? 1 : 0))) {
			last_valid = current;
			current = current->next;
			idx++;
		}

		if (offset) {
			offset--;
		}

	}

	return result;
}
};
