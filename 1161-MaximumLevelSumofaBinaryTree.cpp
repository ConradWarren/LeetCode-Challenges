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
void Tranverse_Tree(TreeNode* root, int depth, std::unordered_map<int, int>& depth_sums) {

	if (root == nullptr) {
		return;
	}

	depth_sums[depth] += root->val;

	Tranverse_Tree(root->left, depth + 1, depth_sums);
	Tranverse_Tree(root->right, depth + 1, depth_sums);
}

int maxLevelSum(TreeNode* root) {
	
	std::unordered_map<int, int> depth_sums;
	int max_sum = 1;

	Tranverse_Tree(root, 1, depth_sums);
	
	
	for (auto& x : depth_sums) {
		max_sum = (depth_sums[max_sum] > x.second) ? max_sum : x.first;
	}

	return max_sum;
}
};
