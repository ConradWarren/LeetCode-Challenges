#include <vector>

class Trie_Node {

public:

	Trie_Node() {
		character_ptrs.resize(26, nullptr);
		end_word_flag = false;
	}
	
	std::vector<Trie_Node*> character_ptrs;
	bool end_word_flag;
};

class StreamChecker {
public:

	StreamChecker(std::vector<std::string>& words) {

		start_point = new Trie_Node();
		current = start_point;

		for (int i = 0; i < words.size(); i++) {

			current = start_point;

			for (int j = words[i].length() - 1; j >= 0; j--) {

				if (current->character_ptrs[words[i][j] - 'a'] == nullptr) {
					current->character_ptrs[words[i][j] - 'a'] = new Trie_Node();
				}

				current = current->character_ptrs[words[i][j] - 'a'];
				if (j == 0) {
					current->end_word_flag = true;
				}
			}
		}
	}

	bool query(char letter) {

		word += letter;
		current = start_point;

		for (int i = word.length() - 1; i >= 0; i--) {

			if (current->character_ptrs[word[i] - 'a'] == nullptr) {
				return false;
			}

			current = current->character_ptrs[word[i] - 'a'];
			if (current->end_word_flag) {
				return true;
			}
		}
		return false;
	}

private:

	Trie_Node* start_point;
	Trie_Node* current;
	std::string word;
};
