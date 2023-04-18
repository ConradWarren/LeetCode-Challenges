
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
void flatten(TreeNode* root) {
	
	if (root == nullptr) {
		return;
	}
	
	flatten(root->left);
	flatten(root->right);

	if (root->left != nullptr) {
		
		TreeNode* Temp_left = root->left;
		TreeNode* Temp_right = root->right;

		
		while (Temp_left->right != nullptr) {
			Temp_left = Temp_left->right;
		}
		Temp_left->right = Temp_right;
		root->right = root->left;
		root->left = nullptr;
	}
}
};
