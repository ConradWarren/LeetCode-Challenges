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
void Tranverse_Tree(TreeNode* root, int depth, std::vector<int>& tree_level_sums) {

	if (root == nullptr) return;
	
	Tranverse_Tree(root->left, depth + 1, tree_level_sums);
	Tranverse_Tree(root->right, depth + 1, tree_level_sums);

	if (depth >= tree_level_sums.size()) tree_level_sums.resize(depth + 1, 0);
	
	tree_level_sums[depth] += root->val;
}

void Modifiy_Tree(TreeNode* root, int sibiling_value, int depth, std::vector<int>& tree_level_sums) {

	if (root == nullptr) return;
	
	int left_child_value = 0;
	int right_child_value = 0;

	if (root->left != nullptr) left_child_value = root->left->val;
	
	if (root->right != nullptr) right_child_value = root->right->val;
	
	root->val = tree_level_sums[depth] - sibiling_value - root->val;

	Modifiy_Tree(root->left, right_child_value, depth + 1, tree_level_sums);
	Modifiy_Tree(root->right, left_child_value, depth + 1, tree_level_sums);
}


TreeNode* replaceValueInTree(TreeNode* root) {

	std::vector<int> tree_level_sums;

	Tranverse_Tree(root, 0, tree_level_sums);

	Modifiy_Tree(root, 0, 0, tree_level_sums);

	return root;
}
};
