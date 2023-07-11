/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
void Depth_First_Search(TreeNode* root, std::unordered_map<int, std::vector<int>>& graph){
	
	if (root == nullptr) {
		return;
	}

	if (root->left != nullptr) {
		graph[root->val].push_back(root->left->val);
		graph[root->left->val].push_back(root->val);
	}
	
	if (root->right != nullptr) {
		graph[root->val].push_back(root->right->val);
		graph[root->right->val].push_back(root->val);
	}

	Depth_First_Search(root->left, graph);
	Depth_First_Search(root->right, graph);
}

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

	std::unordered_map<int, std::vector<int>> graph;
	std::unordered_set<int> visted_nodes;
	std::queue<std::pair<int, int>> node_queue;
	std::vector<int> result;
	int node = 0;
	int current_distance = 0;

	Depth_First_Search(root, graph);

	node_queue.push({ target->val, 0 });
	visted_nodes.insert(target->val);

	while (!node_queue.empty()) {

		node = node_queue.front().first;
		current_distance = node_queue.front().second;
		node_queue.pop();

		if (current_distance == k) {
			result.push_back(node);
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			
			if (visted_nodes.find(graph[node][i]) != visted_nodes.end()) {
				continue;
			}

			visted_nodes.insert(graph[node][i]);

			node_queue.push({ graph[node][i], current_distance + 1 });
		}

	}

	return result;
}
};
