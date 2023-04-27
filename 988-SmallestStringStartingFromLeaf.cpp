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
 
 #include <string>
 
class Solution {
public:
void Find_Smallest_Root_to_Leaf(TreeNode* root, std::string current, std::string& best) {

	if (root == nullptr) {
		return;
	}

	current = char(root->val + int('a')) + current;

	if (root->left == nullptr && root->right == nullptr) {

		if (best.empty() || current < best) {
			best = current;
		}
		return;
	}

	Find_Smallest_Root_to_Leaf(root->left, current, best);
	Find_Smallest_Root_to_Leaf(root->right, current, best);

}

std::string smallestFromLeaf(TreeNode* root) {

	std::string current;
	std::string best;

	Find_Smallest_Root_to_Leaf(root, current, best);


	return best;
}
};
