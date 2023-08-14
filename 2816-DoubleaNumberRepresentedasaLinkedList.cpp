class Solution {
public:
bool Double_List(ListNode* current) {

	if (current == nullptr) {
		return false;
	}

	current->val *= 2;

	if (Double_List(current->next)) {
		current->val++;
	}

	if (current->val > 9) {
		current->val -= 10;
		return true;
	}
	
	return false;
}


ListNode* doubleIt(ListNode* head) {

	if (Double_List(head)) {
		ListNode* result = new ListNode(1);
		result->next = head;
		return result;
	}
	
	return head;
}
};
