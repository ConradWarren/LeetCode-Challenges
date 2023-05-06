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

void Transverse_Tree(TreeNode* root, int val, TreeNode* last_node) {

	if (root == nullptr) {
		last_node->right = new TreeNode(val);
		return;
	}

	if (val > root->val) {
		last_node->right = new TreeNode(val);
		last_node->right->left = root;
		return;
	}

	Transverse_Tree(root->right, val, root);
}

TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

	if (val > root->val) {
		TreeNode* result = new TreeNode(val);
		result->left = root;
		return result;
	}

	Transverse_Tree(root, val, nullptr);

	return root;
}
};
