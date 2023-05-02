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
void Transverse_Tree(TreeNode* root, int depth, std::unordered_map<int, std::pair<long long, int>>& level_sums, int& max_depth) {

	if (root == nullptr) {
		return;
	}

	Transverse_Tree(root->left, depth + 1, level_sums, max_depth);
	Transverse_Tree(root->right, depth + 1, level_sums, max_depth);

	if (level_sums.find(depth) == level_sums.end()) {
		level_sums[depth].first = root->val;
		level_sums[depth].second = 1;
	}
	else {
		level_sums[depth].first += root->val;
		level_sums[depth].second++;
	}

	if (depth > max_depth) {
		max_depth = depth;
	}

}


std::vector<double> averageOfLevels(TreeNode* root) {

	std::unordered_map<int, std::pair<long long, int>> level_sums;
	int max_depth = 0;

	Transverse_Tree(root, 0, level_sums, max_depth);

	std::vector<double> result(max_depth+1);

	for (auto& level : level_sums) {
		result[level.first] = double(level.second.first) / double(level.second.second);
	}

	return result;
}
};
