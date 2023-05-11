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
int Find_Path_Sum_Count(TreeNode* root, long long target_sum) {

	if (root == nullptr) {
		return 0;
	}

	target_sum -= root->val;

	int left = Find_Path_Sum_Count(root->left, target_sum);
	int right = Find_Path_Sum_Count(root->right, target_sum);


	return (target_sum == 0) ? 1 + left + right : left + right;
}


int pathSum(TreeNode* root, int targetSum) {

	if (root == nullptr) {
		return 0;
	}

	int current = Find_Path_Sum_Count(root, targetSum);
	
	int left = pathSum(root->left, targetSum);
	int right = pathSum(root->right, targetSum);

	return left + right + current;
}
};
