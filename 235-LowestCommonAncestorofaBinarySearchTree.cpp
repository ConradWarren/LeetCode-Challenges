#include <unordered_map>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
bool Find_Ancestors(TreeNode* root, TreeNode* target, int depth, std::unordered_map<TreeNode*, int>& ancestors) {

	if (root == nullptr) return false;
	
	if (root == target) {
		ancestors[root] = depth;
		return true;
	}

	if (Find_Ancestors(root->right, target, depth+1, ancestors) || Find_Ancestors(root->left, target, depth + 1, ancestors)) {
		ancestors[root] = depth;
		return true;
	}

	return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	std::unordered_map<TreeNode*, int> ancestors_a;
	std::unordered_map<TreeNode*, int> ancestors_b;

	Find_Ancestors(root, p, 1, ancestors_a);
	Find_Ancestors(root, q, 1, ancestors_b);

	TreeNode* lowest_ancestor = root;
	int lowest_depth = 1;

	for (auto& node : ancestors_a) {
		if (node.second == ancestors_b[node.first] && node.second > lowest_depth) {
			lowest_depth = node.second;
			lowest_ancestor = node.first;
		}
	}

	return lowest_ancestor;
}
};
