/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

	void Tranverse_Tree(TreeNode* root, std::string& key) {

		if (root == nullptr) {
			key += "#,";
			return;
		}

		key += std::to_string(root->val)  + ",";
		Tranverse_Tree(root->left, key);
		Tranverse_Tree(root->right, key);
	}

	TreeNode* Build_Bst(std::vector<TreeNode*>& nodes, int& idx) {

		if (nodes[idx] == nullptr) {
			idx++;
			return nullptr;
		}


		int current_idx = idx;
		idx++;
		nodes[current_idx]->left = Build_Bst(nodes, idx);
		nodes[current_idx]->right = Build_Bst(nodes, idx);

		return nodes[current_idx];
	}
	
public:

	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root) {

		std::string key;

		Tranverse_Tree(root, key);

		return key;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(std::string data) {

		std::vector<TreeNode*> nums;
		std::string current_num;
		for (int i = 0; i < data.length(); i++) {
			if (data[i] != ',' && data[i] != '#') {
				current_num += data[i];
			}
			else if (data[i] == '#') {
				nums.push_back(nullptr);
			}
			else if(!current_num.empty()){
				TreeNode* temp = new TreeNode(std::stoi(current_num));
				nums.push_back(temp);
				current_num.clear();
			}
		}

		

		int idx = 0;
		return Build_Bst(nums, idx);
	}
};
