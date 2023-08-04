class Codec {
public:

	std::string serialize(TreeNode* root) {

		if (root == nullptr) {
			return "#,";
		}
		return std::to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
	}

	TreeNode* Build_Tree(std::vector<int>& nodes, int& idx) {

		if (nodes[idx] == INT_MIN) {
			idx++;
			return nullptr;
		}
		
		TreeNode* current = new TreeNode(nodes[idx]);
		idx++;
		current->left = Build_Tree(nodes, idx);
		current->right = Build_Tree(nodes, idx);

		return current;
	}

	TreeNode* deserialize(std::string data) {

		std::vector<int> nodes;
		std::string current;
		int idx = 0;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == ',' && !current.empty()) {
				nodes.push_back(std::stoi(current));
				current.clear();
			}
			else if (data[i] == '#') {
				nodes.push_back(INT_MIN);
			}
			else if (data[i] != ',') {
				current += data[i];
			}
		}

		return Build_Tree(nodes, idx);
	}
};
