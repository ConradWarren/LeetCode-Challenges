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
TreeNode* Tree_Builder(std::vector<int>& nums, int left_edge, int right_edge) {

	if (left_edge > right_edge) {
		return nullptr;
	}
	
	int max_node = left_edge;

	for (int i = left_edge+1; i <= right_edge; i++) {
		max_node = (nums[max_node] > nums[i]) ? max_node : i;
	}

	TreeNode* node = new TreeNode(nums[max_node]);

	node->left = Tree_Builder(nums, left_edge, max_node - 1);
	node->right = Tree_Builder(nums, max_node + 1, right_edge);

	return node;
}


TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {

	return Tree_Builder(nums, 0, int(nums.size()-1));
}
};
