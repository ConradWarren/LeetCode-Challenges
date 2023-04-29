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
 #include <unordered_map>
 
class Solution {
public:
int Find_All_Subtree_Sums(TreeNode* root, std::unordered_map<int, int>& sum_map, int& highest_occurance) {

	if (root == nullptr) return 0;
	
	int sum = Find_All_Subtree_Sums(root->left, sum_map, highest_occurance) + Find_All_Subtree_Sums(root->right, sum_map, highest_occurance) + root->val;

	sum_map[sum]++;
	highest_occurance = max(highest_occurance, sum_map[sum]);

	return sum;
}

std::vector<int> findFrequentTreeSum(TreeNode* root) {

	int highest_occurance = 0;
	std::unordered_map<int, int> subtree_sum_map;
	std::vector<int> result;

	Find_All_Subtree_Sums(root, subtree_sum_map, highest_occurance);

	for (auto& sum : subtree_sum_map) {
		if (sum.second == highest_occurance) {
			result.push_back(sum.first);
		}
	}

	return result;
}
};
