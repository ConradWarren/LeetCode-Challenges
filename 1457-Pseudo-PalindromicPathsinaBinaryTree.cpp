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
 
 #include <unordered_map>
 
class Solution {
public:
int Tranverse_Tree(TreeNode* root, std::unordered_map<int, int>& num_occurances) {

	if (root == nullptr) {
		return 0;
	}

	if (root->left == nullptr && root->right == nullptr) {

		num_occurances[root->val]++;

		int odd_counter = 0;
		for (auto& num : num_occurances) {
			if (num.second % 2) odd_counter++;
		}
		num_occurances[root->val]--;
		return (odd_counter > 1) ? 0 : 1;
	}

	num_occurances[root->val]++;

	int sum = Tranverse_Tree(root->left, num_occurances) + Tranverse_Tree(root->right, num_occurances);
	 
	num_occurances[root->val]--;

	return sum;
}

int pseudoPalindromicPaths(TreeNode* root) {

	std::unordered_map<int, int> num_occurance;

	return Tranverse_Tree(root, num_occurance);
}
};
