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
void Tranverse_Tree(TreeNode* root, int& max_value, int& min_value, int& sum, bool& is_bst, int& result) {

	if (root == nullptr) {
		max_value = INT_MIN;
		min_value = INT_MAX;
		sum = 0;
		is_bst = true;
		return;
	}

	int left_max = 0;
	int left_min = 0;
	int right_max = 0;
	int right_min = 0;
	int left_sum = 0;
	int right_sum = 0;
	bool left_bst = false;
	bool right_bst = false;

	Tranverse_Tree(root->left, left_max, left_min, left_sum, left_bst, result);
	Tranverse_Tree(root->right, right_max, right_min, right_sum, right_bst, result);

	sum = root->val + left_sum + right_sum;

	if (left_bst && right_bst && right_min > root->val && left_max < root->val) is_bst = true;
	
	else is_bst = false;
	
	min_value = min(root->val, min(left_min, right_min));
	max_value = max(root->val, max(left_max, right_max));

	if (is_bst && sum > result) result = sum;
}

int maxSumBST(TreeNode* root) {

	int sum = 0;
	int min_value = 0;
	int max_value = 0;
	bool is_bst = false;
	int result = 0;

	Tranverse_Tree(root, max_value, min_value, sum, is_bst, result);
	
	return result;
}
};
