#include <vector>

class Trie_Node {

public:
	std::vector<Trie_Node*> character_pointers;
	char character;
	bool end_point;

	Trie_Node(char input) {

		character_pointers.resize(26, nullptr);
		character = input;
		end_point = false;
	}

};



class Trie {
public:
	Trie() {
		current = nullptr;
		start_point_pointers.resize(26, nullptr);
	}

	void insert(std::string word) {

		if (start_point_pointers[int(word[0]) - int('a')] == nullptr) {
			start_point_pointers[int(word[0]) - int('a')] = new Trie_Node(word[0]);
			if (word.length() == 1) start_point_pointers[int(word[0]) - int('a')]->end_point = true;
		}

		current = start_point_pointers[int(word[0]) - int('a')];

		for (int i = 1; i < word.length(); i++) {

			if (current->character_pointers[int(word[i]) - int('a')] == nullptr) {
				current->character_pointers[int(word[i]) - int('a')] = new Trie_Node(word[i]);
			}
			current = current->character_pointers[int(word[i]) - int('a')];
			if (i + 1 == word.length()) current->end_point = true;
		}
	}

	bool search(std::string word) {

		current = start_point_pointers[int(word[0]) - int('a')];

		if (current == nullptr) return false;
		
		for (int i = 1; i < word.length(); i++) {
			current = current->character_pointers[int(word[i]) - int('a')];
			if (current == nullptr) return false;
		}
		
		return current->end_point;
	}

	bool startsWith(std::string word) {

		current = start_point_pointers[int(word[0]) - int('a')];

		if (current == nullptr) return false;
		
		for (int i = 1; i < word.length(); i++) {
			current = current->character_pointers[int(word[i]) - int('a')];
			if (current == nullptr) return false;
		}
		return true;
	}

private:
	std::vector<Trie_Node*> start_point_pointers;
	Trie_Node* current;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
