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
int Solve_Min_Cameras(TreeNode* root, bool monitored, bool parent_monitored, std::vector<std::unordered_map<TreeNode*, int>>& cache) {

	if (root == nullptr) return 0;
	
	if (!monitored && !parent_monitored) return 1 + Solve_Min_Cameras(root->left, true, true, cache) + Solve_Min_Cameras(root->right, true, true, cache);
	
	if (monitored) {

		if (cache[0].find(root) != cache[0].end()) return cache[0][root];
		
		int place_camera = 1 + Solve_Min_Cameras(root->left, true, true, cache) + Solve_Min_Cameras(root->right, true, true, cache);
		int skip = Solve_Min_Cameras(root->left, false, true, cache) + Solve_Min_Cameras(root->right, false, true, cache);

		cache[0][root] = (skip < place_camera) ? skip : place_camera;

		return cache[0][root];
	}

	if (cache[1].find(root) != cache[1].end()) return cache[1][root];
	
	int place_camera = 1 + Solve_Min_Cameras(root->left, true, true, cache) + Solve_Min_Cameras(root->right, true, true, cache);
	int place_camera_left = (root->left == nullptr) ? INT_MAX : Solve_Min_Cameras(root->left, false, false, cache) + Solve_Min_Cameras(root->right, false, true, cache);
	int place_camera_right = (root->right == nullptr) ? INT_MAX : Solve_Min_Cameras(root->left, false, true, cache) + Solve_Min_Cameras(root->right, false, false, cache);

	cache[1][root] = (place_camera < place_camera_left && place_camera < place_camera_right) ? place_camera : (place_camera_left < place_camera_right) ? place_camera_left : place_camera_right;

	return cache[1][root];
}

int minCameraCover(TreeNode* root) {

	std::vector<std::unordered_map<TreeNode*, int>> cache(2);

	return Solve_Min_Cameras(root, false, true, cache);
}
};
