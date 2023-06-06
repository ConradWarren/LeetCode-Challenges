#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
bool Is_Valid(std::string& s, std::string& sub, std::unordered_map<char, std::unordered_set<char>>& character_map, int idx) {

	for (int i = 0; i < sub.length(); i++) {

		if (s[idx + i] == sub[i]) {
			continue;
		}

		if (character_map.find(sub[i]) != character_map.end() && character_map[sub[i]].find(s[idx + i]) != character_map[sub[i]].end()) {
			continue;
		}
		return false;
	}

	return true;
}

bool matchReplacement(std::string s, std::string sub, std::vector<std::vector<char>>& mappings) {

	std::unordered_map<char, std::unordered_set<char>> character_map;

	for (int i = 0; i < mappings.size(); i++) {
		character_map[mappings[i][0]].insert(mappings[i][1]);
	}

	for (int i = 0; i < s.length()-sub.length()+1; i++) {
		
		if (s[i] == sub[0] && Is_Valid(s, sub, character_map, i)) {
			return true;
		}
		else if (character_map.find(sub[0]) != character_map.end() && character_map[sub[0]].find(s[i]) != character_map[sub[0]].end() && Is_Valid(s, sub, character_map, i)) {
			return true;
		}
	}

	return false;
}
};
