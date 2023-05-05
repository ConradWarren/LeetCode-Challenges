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
 
#include <queue>

class Solution {
public:
bool isCompleteTree(TreeNode* root) {

	std::queue<TreeNode*> tree;
	tree.push(root);
	bool null_found = false;

	while (!tree.empty()) {
		TreeNode* current = tree.front();
		tree.pop();
		if (current == nullptr) {
			null_found = true;
		}
		else {
			if (null_found) {
				return false;
			}
			tree.push(current->left);
			tree.push(current->right);
		}
	}


	return true;
}
};
