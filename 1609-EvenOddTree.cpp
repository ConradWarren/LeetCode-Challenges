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
bool Tranverse_Tree(TreeNode* root, int depth, std::vector<int>& depth_cache) {

	if (root == nullptr) return true;
	
	bool left_subtree = Tranverse_Tree(root->left, depth + 1, depth_cache);
	bool right_subtree = Tranverse_Tree(root->right, depth + 1, depth_cache);

	if (!left_subtree || !right_subtree) return false;
	
	if (depth >= depth_cache.size()) depth_cache.resize(depth + 1, -1);
	
	if (root->val % 2 == depth % 2) return false;
	
	if (depth_cache[depth] == -1) {
		depth_cache[depth] = root->val;
		return true;
	}

	if (depth % 2 == 0 && depth_cache[depth] >= root->val) return false;
	
	if (depth % 2 == 1 && depth_cache[depth] <= root->val) return false;
	
	depth_cache[depth] = root->val;

	return true;
}

bool isEvenOddTree(TreeNode* root) {

	std::vector<int> depth_cache;

	return Tranverse_Tree(root, 0, depth_cache);
}
};
