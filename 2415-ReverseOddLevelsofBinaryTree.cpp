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
void Tranverse_Tree(TreeNode* root, int depth, std::vector<std::vector<int>>& tree_vec) {

	if (root == nullptr) return;
	
	Tranverse_Tree(root->left, depth + 1, tree_vec);
	Tranverse_Tree(root->right, depth + 1, tree_vec);

	if (depth >= tree_vec.size()) tree_vec.resize(depth + 1);
	
	tree_vec[depth].push_back(root->val);
}

void Rebuild_Tree(TreeNode* root, int depth, std::vector<std::vector<int>>& tree_vec) {

	if (root == nullptr) return;
	
	Rebuild_Tree(root->left, depth + 1, tree_vec);
	Rebuild_Tree(root->right, depth + 1, tree_vec);

	if (depth % 2) {
		root->val = tree_vec[depth].back();
		tree_vec[depth].pop_back();
	}

}

TreeNode* reverseOddLevels(TreeNode* root) {

	std::vector<std::vector<int>> tree_vec;

	Tranverse_Tree(root, 0, tree_vec);

	Rebuild_Tree(root, 0, tree_vec);

	return root;
}
};
