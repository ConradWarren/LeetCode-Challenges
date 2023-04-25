#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:
std::string frequencySort(std::string s) {

	std::unordered_map<char, int> character_occurances;
	std::vector<std::pair<int, char>> sortable_characters;

	for (int i = 0; i < s.length(); i++) {
		character_occurances[s[i]]++;
	}

	for (auto& character : character_occurances) {
		sortable_characters.push_back({ character.second, character.first });
	}

	std::sort(sortable_characters.rbegin(), sortable_characters.rend());

	int idx = 0;
	for (int i = 0; i < sortable_characters.size(); i++) {

		for (int j = 0; j < sortable_characters[i].first; j++) {
			s[idx] = sortable_characters[i].second;
			idx++;
		}
	}

	return s;
}
};
