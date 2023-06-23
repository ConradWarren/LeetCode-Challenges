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
int Sub_Tree_Sum(TreeNode* root, int& tilt_sum) {

	if (root == nullptr) {
		return 0;
	}

	int left = Sub_Tree_Sum(root->left, tilt_sum);
	int right = Sub_Tree_Sum(root->right, tilt_sum);

	tilt_sum += std::abs(left - right);
	
	return left + right + root->val;
}

int findTilt(TreeNode* root) {

	int tilt_sum = 0;
	
	Sub_Tree_Sum(root, tilt_sum);

	return tilt_sum;
}
};
