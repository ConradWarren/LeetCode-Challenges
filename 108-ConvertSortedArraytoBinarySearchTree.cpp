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
TreeNode* BST_Builder(std::vector<TreeNode*>& nodes, int low, int high) {

	if (low > high) return nullptr;
	
	int mid_point = (low + high) / 2;

	nodes[mid_point]->left = BST_Builder(nodes, low, mid_point-1);
	nodes[mid_point]->right = BST_Builder(nodes, mid_point + 1, high);

	return nodes[mid_point];
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {

	std::vector<TreeNode*> nodes(nums.size(), nullptr);

	for (int i = 0; i < nodes.size(); i++) {
		nodes[i] = new TreeNode(nums[i]);
	}

	return BST_Builder(nodes, 0, nodes.size()-1);
}
};
