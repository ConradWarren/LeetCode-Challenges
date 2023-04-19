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
int Max_Depth(TreeNode* root) {

	if (root == nullptr) {
		return 0; 
	}

	int left_depth = 1 + Max_Depth(root->left);
	int right_depth = 1 + Max_Depth(root->right);

	if (left_depth <= 0 || right_depth <= 0) {
		return -1;
	}

	if (abs(left_depth - right_depth) > 1) {
		return -1;
	}


	return (left_depth > right_depth) ? left_depth : right_depth;
}


bool isBalanced(TreeNode* root) {


	if (Max_Depth(root) == -1) {
		return false;
	}

	return true;
}
};
