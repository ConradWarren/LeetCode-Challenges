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
void Transverse_Tree(TreeNode* root,TreeNode* parent_node,bool left_flag, std::unordered_map<int, bool>& to_delete, std::vector<TreeNode*>& result) {

	if (root == nullptr) return;
	
	if (to_delete[root->val]) {

		TreeNode* temp_left = root->left;
		TreeNode* temp_right = root->right;

		if (temp_left != nullptr && !to_delete[temp_left->val]) {
			result.push_back(temp_left);
		}
		if (temp_right != nullptr && !to_delete[temp_right->val]) {
			result.push_back(temp_right);
		}

		if (parent_node != nullptr) {
			if (left_flag) parent_node->left = nullptr;
			else parent_node->right = nullptr;
		}

		delete root;

		Transverse_Tree(temp_left,nullptr,true, to_delete, result);
		Transverse_Tree(temp_right,nullptr,false, to_delete, result);
		return;
	}
	
	Transverse_Tree(root->left,root,true, to_delete, result);
	Transverse_Tree(root->right,root,false, to_delete, result);
}

std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {

	std::unordered_map<int, bool> to_delete_map;
	std::vector<TreeNode*> result;

	for (int i = 0; i < to_delete.size(); i++) {
		to_delete_map[to_delete[i]] = true;
	}

	if (!to_delete_map[root->val]) result.push_back(root);
	
	Transverse_Tree(root, nullptr,true, to_delete_map, result);

	return result;
}
};
