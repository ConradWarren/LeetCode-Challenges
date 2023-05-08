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

void Tranverse_Tree(TreeNode* root, std::vector<TreeNode*>& sub_tree_arr) {

	if (root == nullptr) return;
	
	sub_tree_arr.push_back(root);

	Tranverse_Tree(root->left, sub_tree_arr);
	Tranverse_Tree(root->right, sub_tree_arr);
}

TreeNode* Buid_BST(int& idx,int min, int max, std::vector<TreeNode*>& sub_tree_arr) {

	if (idx >= sub_tree_arr.size() || sub_tree_arr[idx]->val <= min || sub_tree_arr[idx]->val >= max) {
		return nullptr;
	}

	TreeNode* temp = sub_tree_arr[idx];

	idx++;
	temp->left = Buid_BST(idx, min, temp->val, sub_tree_arr);
	temp->right = Buid_BST(idx, temp->val, max, sub_tree_arr);

	return temp;
}


void Find_Node(TreeNode* root,TreeNode* parent_node, int key) {

	if (root == nullptr) return;
	
	if (key > root->val) {
		Find_Node(root->right,root, key);
		return;
	}

	if (key < root->val) {
		Find_Node(root->left,root, key);
		return;
	}

	std::vector<TreeNode*> sub_tree_arr;
	Tranverse_Tree(root, sub_tree_arr);

	int idx = 1;
	TreeNode* rebuilt_bst = Buid_BST(idx, INT_MIN, INT_MAX, sub_tree_arr);

	if (parent_node->val > key) parent_node->left = rebuilt_bst;
	
	else parent_node->right = rebuilt_bst;
	
	delete root;
}

TreeNode* deleteNode(TreeNode* root, int key) {

	TreeNode* parent_node_placeholder = new TreeNode(INT_MAX);
	parent_node_placeholder->left = root;

	Find_Node(root, parent_node_placeholder, key);

	root = parent_node_placeholder->left;
	delete parent_node_placeholder;

	return root;
}
};
