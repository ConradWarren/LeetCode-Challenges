
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
void Build_Preorder_Vector(TreeNode* root, std::vector<int>& result) {

	if (root == nullptr) {
		return;
	}

	result.push_back(root->val);

	Build_Preorder_Vector(root->left, result);
	Build_Preorder_Vector(root->right, result);

}

std::vector<int> preorderTraversal(TreeNode* root) {

	std::vector<int> result;

	Build_Preorder_Vector(root, result);

	return result;
}
};
