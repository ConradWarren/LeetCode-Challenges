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
#include <string>
#include <cmath>

class Solution {
public:
int Tree_Height(TreeNode* root) {

	if (root == nullptr) return 0;
	
	int left_height = Tree_Height(root->left);
	int right_height = Tree_Height(root->right);

	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

void Tranverse_Tree(TreeNode* root,int coloum, int row,int height, std::vector<std::vector<std::string>>& result) {

	if (root == nullptr) return;
	
	result[row][coloum] = std::to_string(root->val);

	Tranverse_Tree(root->left, coloum - std::pow(2, height - row - 2), row + 1, height, result);
	Tranverse_Tree(root->right, coloum + std::pow(2, height - row - 2), row + 1,height, result);
}

std::vector<std::vector<std::string>> printTree(TreeNode* root) {

	int height = Tree_Height(root);
	int columns = std::pow(2, height) - 1;
	std::vector<std::vector<std::string>> result(height, std::vector<std::string>(columns, ""));

	Tranverse_Tree(root,columns / 2, 0, height, result);

	return result;
}
};
