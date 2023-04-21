#include <string>
#include <unordered_map>

class Solution {
public:
bool wordPattern(std::string pattern, std::string s) {

	std::vector<std::string> words;
	std::string current_word;
	std::unordered_map<char, std::string> pattern_map;
	std::unordered_map<std::string, char> word_map;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' && !current_word.empty()) {
			words.push_back(current_word);
			current_word.clear();
		}
		else if (s[i] != ' ') current_word += s[i];
	}
	if (!current_word.empty()) words.push_back(current_word);

	if (int(words.size()) != int(pattern.length())) return false;
	
	for (int i = 0; i < pattern.size(); i++) {

		if (pattern_map.find(pattern[i]) == pattern_map.end()) pattern_map[pattern[i]] = words[i];
		
		else if (pattern_map[pattern[i]] != words[i]) return false;
		
	}

	for (int i = 0; i < words.size(); i++) {

		if (word_map.find(words[i]) == word_map.end()) word_map[words[i]] = pattern[i];
		
		else if (word_map[words[i]] != pattern[i]) return false;
		
	}

	return true;
}
};
