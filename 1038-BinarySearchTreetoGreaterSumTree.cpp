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
int Find_Sum_of_Node(TreeNode* root) {

	if (root == nullptr) return 0;
	
	return root->val + Find_Sum_of_Node(root->left) + Find_Sum_of_Node(root->right);
}

void Tranverse_Tree(TreeNode* root, int& sum) {

	if (root == nullptr) return;
	
	Tranverse_Tree(root->left, sum);

	int old_root_val = root->val;
	root->val = sum;
	sum -= old_root_val;

	Tranverse_Tree(root->right, sum);
}

TreeNode* bstToGst(TreeNode* root) {

	int sum = Find_Sum_of_Node(root);

	Tranverse_Tree(root, sum);
	return root;
}
};
