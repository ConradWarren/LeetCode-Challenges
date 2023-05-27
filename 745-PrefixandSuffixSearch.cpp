class Trie_Node {
public:
	std::vector<int> word_idx;
	std::unordered_map<char, Trie_Node*> character_pointers;
};

class WordFilter {
public:

	void Add_Word(std::string& word, int idx) {

		Trie_Node* current = nullptr;

		if (starting_pointers.find(word[0]) == starting_pointers.end()) {
			starting_pointers[word[0]] = new Trie_Node();
		}
		current = starting_pointers[word[0]];
		current->word_idx.push_back(idx);

		for (int i = 1; i < word.length(); i++) {

			if (current->character_pointers.find(word[i]) == current->character_pointers.end()) {
				current->character_pointers[word[i]] = new Trie_Node();
			}
			current = current->character_pointers[word[i]];
			current->word_idx.push_back(idx);
		}
	}

	WordFilter(std::vector<std::string>& words) {

		word_cache = words;

		for (int i = 0; i < words.size(); i++) {
			Add_Word(words[i], i);
		}
	}

	int f(std::string pref, std::string suff) {

		Trie_Node* current = nullptr;

		if (starting_pointers.find(pref[0]) == starting_pointers.end()) return -1;
		
		current = starting_pointers[pref[0]];

		for (int i = 1; i < pref.length(); i++) {

			if (current->character_pointers.find(pref[i]) == current->character_pointers.end()) return -1;
		
			current = current->character_pointers[pref[i]];
		}

		for (int i = current->word_idx.size()-1; i >= 0; i--) {
			if (suff.length() <= word_cache[current->word_idx[i]].length() && suff == word_cache[current->word_idx[i]].substr(word_cache[current->word_idx[i]].length() - suff.length())) {
				return current->word_idx[i];
			}
		}
		return -1;
	}
private:
	std::unordered_map<char, Trie_Node*> starting_pointers;
	std::vector<std::string> word_cache;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
