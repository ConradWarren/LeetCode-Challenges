/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <vector>

class Solution {
public:
void Transverse_Tree(Node* root, int depth, std::vector<std::vector<Node*>>& ordered_tree) {

	if (root == nullptr) {
		return;
	}

	Transverse_Tree(root->left, depth + 1, ordered_tree);
	Transverse_Tree(root->right, depth + 1, ordered_tree);

	if (depth >= ordered_tree.size()) {
		ordered_tree.resize(depth + 1);
	}

	ordered_tree[depth].push_back(root);
}

Node* connect(Node* root) {

	std::vector<std::vector<Node*>> ordered_tree;

	Transverse_Tree(root, 0, ordered_tree);

	for (int i = 0; i < ordered_tree.size(); i++) {
		for (int j = 0; j < ordered_tree[i].size() - 1; j++) {

			ordered_tree[i][j]->next = ordered_tree[i][j + 1];

		}
	}

	return root;
}
};
