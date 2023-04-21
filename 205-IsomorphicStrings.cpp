#include <string>

class Solution {
public:
bool isIsomorphic(std::string s, std::string t) {

	std::unordered_map<char, std::vector<int>> s_character_indexs;
	std::unordered_map<char, std::vector<int>> t_character_indexs;

	for (int i = 0; i < s.length(); i++) {
		s_character_indexs[s[i]].push_back(i);
		t_character_indexs[t[i]].push_back(i);
	}

	for (int i = 0; i < s.length(); i++) {
		if (s_character_indexs[s[i]] != t_character_indexs[t[i]]) {
			return false;
		}
	}

	return true;
}
};
