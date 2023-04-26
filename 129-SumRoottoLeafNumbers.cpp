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
void Solve_Root_To_Leaf_Sums(TreeNode* root, int current, int& sum) {

	if (root == nullptr) {
		return;
	}
	
	current *= 10;
	current += root->val;

	if (root->right == nullptr && root->left == nullptr) {
		sum += current;
		return;
	}

	Solve_Root_To_Leaf_Sums(root->left, current, sum);
	Solve_Root_To_Leaf_Sums(root->right, current, sum);

}

int sumNumbers(TreeNode* root) {
	
	int sum = 0;

	Solve_Root_To_Leaf_Sums(root, 0, sum);
	
	return sum;
}
};
