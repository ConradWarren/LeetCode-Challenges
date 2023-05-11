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
void Find_Target_Sums(TreeNode* root, int target_sum, std::vector<int>& current_path, std::vector<std::vector<int>>& result) {

	if (root == nullptr) {
		return;
	}

	current_path.push_back(root->val);

	target_sum -= root->val;

	if (root->left == nullptr && root->right == nullptr && target_sum == 0) {
		result.push_back(current_path);
		current_path.pop_back();
		return;
	}

	Find_Target_Sums(root->left, target_sum, current_path, result);
	Find_Target_Sums(root->right, target_sum, current_path, result);

	current_path.pop_back();

}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum){

	std::vector<std::vector<int>> result;
	std::vector<int> current_path;

	Find_Target_Sums(root, targetSum, current_path, result);

	return result;
}
