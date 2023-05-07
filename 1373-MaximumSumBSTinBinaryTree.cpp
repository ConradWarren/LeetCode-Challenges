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

class NodeInfo {
public:
	int sum;
	int max_value;
	int min_value;
	bool is_bst;
};

class Solution {
public:
void Tranverse_Tree(TreeNode* root, std::unordered_map<TreeNode*, NodeInfo>& node_map, std::unordered_map<TreeNode*, bool>& bst_map) {

	if (root == nullptr) {
		return;
	}

	Tranverse_Tree(root->left, node_map, bst_map);
	Tranverse_Tree(root->right, node_map, bst_map);

	node_map[root].sum = root->val + node_map[root->left].sum + node_map[root->right].sum;
	node_map[root].min_value = (node_map[root->left].min_value < node_map[root->right].min_value) ? node_map[root->left].min_value : node_map[root->right].min_value;
	node_map[root].min_value = (node_map[root].min_value < root->val) ? node_map[root].min_value : root->val;

	node_map[root].max_value = (node_map[root->left].max_value > node_map[root->right].max_value) ? node_map[root->left].max_value : node_map[root->right].max_value;
	node_map[root].max_value = (node_map[root].max_value > root->val) ? node_map[root].max_value : root->val;

	if (node_map[root->right].min_value > root->val && node_map[root->left].max_value < root->val && node_map[root->left].is_bst && node_map[root->right].is_bst) {
		bst_map[root] = true;
		node_map[root].is_bst = true;
	}
	else {
		node_map[root].is_bst = false;
	}
}



int maxSumBST(TreeNode* root) {
	
	std::unordered_map<TreeNode*, bool> bst_map;
	std::unordered_map<TreeNode*, NodeInfo> node_map;

	node_map[nullptr].is_bst = true;
	node_map[nullptr].sum = 0;
	node_map[nullptr].max_value = INT_MIN;
	node_map[nullptr].min_value = INT_MAX;

	Tranverse_Tree(root, node_map, bst_map);

	int best_sum = 0;
	for (auto& node : bst_map) {
		best_sum = (best_sum > node_map[node.first].sum) ? best_sum : node_map[node.first].sum;
	}

	return best_sum;
}
};
