#include <unordered_map>

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
void solve_width(TreeNode* root,unsigned long long current_position, int current_depth, int& best, std::unordered_map<int,unsigned long long>& node_position) {

	if (root == nullptr) {
		return;
	}

	solve_width(root->left, (current_position * 2) + 1, current_depth + 1, best, node_position);
	solve_width(root->right, (current_position * 2) + 2, current_depth + 1, best, node_position);

	if (node_position.find(current_depth) == node_position.end()) {
		node_position[current_depth] = current_position;
	}

	if (best < current_position - node_position[current_depth]) {
		best = current_position - node_position[current_depth];
	}

}

int widthOfBinaryTree(TreeNode* root) {
	
	int best = 0;
	std::unordered_map<int,unsigned long long> node_positions;
	
	solve_width(root, 0, 0, best, node_positions);

	return best+1;
}
};
