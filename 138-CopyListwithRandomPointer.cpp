/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void Copy_List(Node* head, std::unordered_map<Node*, Node*>& cache) {

	if (head == nullptr) {
		return;
	}

	if (cache.find(head) != cache.end()) {
		return;
	}

	cache[head] = new Node(head->val);

	Copy_List(head->next, cache);
	Copy_List(head->random, cache);

	cache[head]->next = cache[head->next];
	cache[head]->random = cache[head->random];
}

Node* copyRandomList(Node* head) {

	std::unordered_map<Node*, Node*> deep_copy;

	Copy_List(head, deep_copy);

	return deep_copy[head];
}
};
