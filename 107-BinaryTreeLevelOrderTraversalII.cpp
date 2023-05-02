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

#include <vector>
 
class Solution {
public:
void Transverse_Tree(TreeNode* root, int depth, std::vector<std::vector<int>>& level_order_tree) {

	if (root == nullptr) {
		return;
	}

	Transverse_Tree(root->left, depth + 1, level_order_tree);
	Transverse_Tree(root->right, depth + 1, level_order_tree);

	if (depth >= level_order_tree.size()) {
		level_order_tree.resize(depth + 1);
	}

	level_order_tree[depth].push_back(root->val);
}

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {

	std::vector<std::vector<int>> level_order_tree;

	Transverse_Tree(root, 0, level_order_tree);

	std::reverse(level_order_tree.begin(), level_order_tree.end());

	return level_order_tree;
}
};
