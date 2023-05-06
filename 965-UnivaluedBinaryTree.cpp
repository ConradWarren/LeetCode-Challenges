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
bool Transverse_Tree(TreeNode* root, int value) {

	if (root == nullptr) {
		return true;
	}

	if (root->val != value) {
		return false;
	}

	if (Transverse_Tree(root->left, value) && Transverse_Tree(root->right, value)) {
		return true;
	}

	return false;
}

bool isUnivalTree(TreeNode* root) {
	
	return Transverse_Tree(root, root->val);
}
};
