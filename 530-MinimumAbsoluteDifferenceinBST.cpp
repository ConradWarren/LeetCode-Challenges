#include <vector>

class Solution {
public:
void Tranverse_Tree(TreeNode* root, std::vector<int>& sorted_tree) {

	if (root == nullptr) {
		return;
	}

	Tranverse_Tree(root->left, sorted_tree);
	sorted_tree.push_back(root->val);
	Tranverse_Tree(root->right, sorted_tree);

}

int getMinimumDifference(TreeNode* root) {

	std::vector<int> sorted_tree;
	int min_diffrence = INT_MAX;

	Tranverse_Tree(root, sorted_tree);

	for (int i = 0; i < sorted_tree.size()-1; i++) {

		min_diffrence = (min_diffrence < (sorted_tree[i + 1] - sorted_tree[i])) ? min_diffrence : (sorted_tree[i + 1] - sorted_tree[i]);

	}
	
	return min_diffrence;
}
};
