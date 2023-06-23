/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool Subtree_Contains_One(TreeNode* root) {

	if (root == nullptr) {
		return false;
	}

	bool left_subtree = Subtree_Contains_One(root->left);
	bool right_subtree = Subtree_Contains_One(root->right);

	if (!left_subtree) {
		root->left = nullptr;
		delete root->left;
	}

	if (!right_subtree) {
		root->right = nullptr;
		delete root->right;
	}

	return (left_subtree || right_subtree || root->val == 1);
}


TreeNode* pruneTree(TreeNode* root) {

	if (!Subtree_Contains_One(root)) {
		return nullptr;
	}

	return root;
}
};
