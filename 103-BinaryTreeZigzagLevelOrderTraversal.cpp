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
void Tranverse_Tree(TreeNode* root, int depth, std::vector<std::vector<int>>& result) {

	if (root == nullptr) {
		return;
	}

	Tranverse_Tree(root->left, depth + 1, result);
	Tranverse_Tree(root->right, depth + 1, result);

	if (depth >= result.size()) {
		result.resize(depth + 1);
	}

	result[depth].push_back(root->val);
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
	
	std::vector<std::vector<int>> result;

	Tranverse_Tree(root, 0, result);

	for (int i = 1; i < result.size(); i += 2) {
		std::reverse(result[i].begin(), result[i].end());
	}


	return result;
}
};
