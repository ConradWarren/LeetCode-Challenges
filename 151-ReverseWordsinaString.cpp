#include <vector>
#include <string>

class Solution {
public:
std::string reverseWords(std::string s) {

	std::string current_word;
	std::vector<std::string> words;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == ' ' && !current_word.empty()) {
			words.push_back(current_word);
			current_word.clear();
		}
		else if (s[i] != ' ') {
			current_word += s[i];
		}
	}

	if (!current_word.empty()) {
		words.push_back(current_word);
		current_word.clear();
	}

	for (int i = words.size() - 1; i >= 1; i--) {
		current_word += words[i] + ' ';
	}
	current_word += words[0];

	return current_word;
}
};
