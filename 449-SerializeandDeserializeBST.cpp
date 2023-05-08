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

private:

	void Tranverse_Tree_In_Order(TreeNode* root, std::string& key) {

		if (root == nullptr) return;
		
		key += std::to_string(root->val) + ',';

		Tranverse_Tree_In_Order(root->left, key);
		Tranverse_Tree_In_Order(root->right, key);
	}

	TreeNode* Decode_Key(int& idx, int min, int max, std::vector<int>& values) {

		if (idx >= values.size() || values[idx] <= min || values[idx] >= max) {
			return nullptr;
		}
		
		TreeNode* current = new TreeNode(values[idx]);

		idx++;

		current->left = Decode_Key(idx, min, current->val, values);

		current->right = Decode_Key(idx, current->val, max, values);

		return current;
	}

public:

	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root) {

		std::string key;

		Tranverse_Tree_In_Order(root, key);

		return key;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(std::string data) {

		std::vector<int> values;
		std::string current_value;

		for (int i = 0; i < data.size(); i++) {

			if (data[i] != ',') current_value += data[i];
			
			else {
				values.push_back(stoi(current_value));
				current_value.clear();
			}
		}

		int idx = 0;
		return Decode_Key(idx, INT_MIN, INT_MAX, values);
	}
};
