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
void Tranverse_Tree(TreeNode* root, std::vector<int>& result) {

	if (root == nullptr) return;
	
	Tranverse_Tree(root->left, result);
	result.push_back(root->val);
	Tranverse_Tree(root->right, result);
}

int kthSmallest(TreeNode* root, int k) {

	std::vector<int> result;

	Tranverse_Tree(root, result);

	return result[k-1];
}
};
