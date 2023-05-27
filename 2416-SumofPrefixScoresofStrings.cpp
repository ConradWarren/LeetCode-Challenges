class Trie_Node {
public:
	Trie_Node* character_pointers[26];
	int count;
	
	Trie_Node() {
		count = 0;
		for (int i = 0; i < 26; i++) {
			character_pointers[i] = nullptr;
		}
	}
};


class Solution {
public:
std::vector<int> sumPrefixScores(std::vector<std::string>& words) {

	std::vector<int> result(words.size(), 0);
	Trie_Node* starting_points[26];
	Trie_Node* current = nullptr;
	
	for (int i = 0; i < 26; i++) {
		starting_points[i] = nullptr;
	}

	for (int i = 0; i < words.size(); i++) {

		if (starting_points[words[i][0] - 'a'] == nullptr) {
			starting_points[words[i][0] - 'a'] = new Trie_Node();
		}

		current = starting_points[words[i][0]-'a'];
		current->count++;

		for (int j = 1; j < words[i].length(); j++) {

			if (current->character_pointers[words[i][j] - 'a'] == nullptr) {
				current->character_pointers[words[i][j] - 'a'] = new Trie_Node();
			}
			current = current->character_pointers[words[i][j] - 'a'];
			current->count++;
		}
	}

	for (int i = 0; i < words.size(); i++) {

		current = starting_points[words[i][0]-'a'];
		result[i] += current->count;

		for (int j = 1; j < words[i].length(); j++) {

			current = current->character_pointers[words[i][j]-'a'];
			result[i] += current->count;
		}

	}
	return result;
}
};
