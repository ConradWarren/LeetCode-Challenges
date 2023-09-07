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
ListNode* reverseList(ListNode* head) {

	if (head == NULL) {
		return head;
	}

	ListNode* Last = nullptr;
	ListNode* Next = head->next;

	while (head->next != nullptr) {
		head->next = Last;
		Last = head;
		head = Next;
		Next = head->next;
	}

	head->next = Last;

	return head;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {

	if (head == NULL) {
		return head;
	}

	ListNode* Current = head;
	ListNode* Last = nullptr;

	int idx = 1;

	while (idx < left && Current->next != NULL) {
		idx++;
		Last = Current;
		Current = Current->next;
	}
	ListNode* First_node_to_be_reversed = Current;
	

	while (idx < right && Current->next != NULL) {
		idx++;
		Current = Current->next;
	}

	ListNode* End = Current->next;
	Current->next = nullptr;

	ListNode* Reversed_List = reverseList(First_node_to_be_reversed);
	if (Last != NULL) {
		Last->next = Reversed_List;
	}
	else {
		head = Reversed_List;
	}
	
	First_node_to_be_reversed->next = End;

	return head;
}
};
