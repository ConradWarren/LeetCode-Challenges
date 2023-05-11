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
TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {

	std::unordered_map<int, TreeNode*> tree_map;
	std::unordered_map<int, int> parent_nodes;

	int current_root = descriptions[0][0];

	for (int i = 0; i < descriptions.size(); i++) {

		if (tree_map.find(descriptions[i][0]) == tree_map.end()) {
			tree_map[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
		}

		if (tree_map.find(descriptions[i][1]) == tree_map.end()) {
			tree_map[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
		}

		if (descriptions[i][2]) {
			tree_map[descriptions[i][0]]->left = tree_map[descriptions[i][1]];
		}
		else {
			tree_map[descriptions[i][0]]->right = tree_map[descriptions[i][1]];
		}

		parent_nodes[descriptions[i][1]] = descriptions[i][0];

		if (descriptions[i][1] == current_root) {

			while (parent_nodes.find(current_root) != parent_nodes.end()) {
				current_root = parent_nodes[current_root];
			}

		}
	}

	return tree_map[current_root];
}
};
