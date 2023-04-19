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
int Solve(TreeNode* root, bool right_flag, int current_length) {

	if (root == nullptr) {
		return current_length - 1;
	}

	int right_distance = (right_flag) ? Solve(root->right, true, 1) : Solve(root->right, true, current_length + 1);
	int left_distance = (right_flag) ? Solve(root->left, false, current_length + 1) : Solve(root->left, false, 1);
	
	return max(right_distance, left_distance);
}


int longestZigZag(TreeNode* root) {


	int right_distance = Solve(root, true, 0);
	int left_distance = Solve(root, false, 0);

	
	return max(right_distance, left_distance);
}
};
