#include <unordered_map>
#include <string>

class Trie_Node {

public:
	std::unordered_map<char, Trie_Node*> character_pointers;
	bool end_point;

	Trie_Node() {
		end_point = false;
	}
};

class WordDictionary {
public:
	WordDictionary() {
		
	}

	void addWord(std::string word) {

		Trie_Node* current = nullptr;
		if (starting_points.find(word[0]) == starting_points.end()) {
			starting_points[word[0]] = new Trie_Node();
		}

		current = starting_points[word[0]];
		if (word.length() == 1) current->end_point = true;

		for (int i = 1; i < word.length(); i++) {

			if (current->character_pointers.find(word[i]) == current->character_pointers.end()) {
				current->character_pointers[word[i]] = new Trie_Node();
			}
			current = current->character_pointers[word[i]];
			if (i + 1 == word.length()) current->end_point = true;
		}

	}

	bool Recursive_Search(int idx, Trie_Node* current, std::string& word) {


		if (idx >= word.length()) {
			if (current->end_point) return true;

			else return false;
		}

		if (idx == 0 && word[idx] == '.') {
			for (auto& x : starting_points) {
				if (Recursive_Search(idx+1, x.second, word)) return true;
			}

			return false;
		}

		if (idx == 0) {
			if (starting_points.find(word[idx]) == starting_points.end()) return false;
			
			return Recursive_Search(idx + 1, starting_points[word[idx]], word);
		}

		if (word[idx] == '.') {
			for (auto& x : current->character_pointers) {
				if (Recursive_Search(idx + 1, x.second, word)) return true;
			}

			return false;
		}

		if (current->character_pointers.find(word[idx]) == current->character_pointers.end()) return false;
		
		return Recursive_Search(idx + 1, current->character_pointers[word[idx]], word);
	}

	bool search(std::string word) {

		return Recursive_Search(0, nullptr, word);
	}

private:
	std::unordered_map<char, Trie_Node*> starting_points;
	
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
