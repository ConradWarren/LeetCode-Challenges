#include <unordered_map>
#include <string>

class Solution {
public:
std::string sortVowels(std::string s) {

	std::unordered_map<char, bool> vowel_map;
	std::string vowel_string;
	vowel_map['a'] = true;
	vowel_map['e'] = true;
	vowel_map['i'] = true;
	vowel_map['o'] = true;
	vowel_map['u'] = true;
	vowel_map['A'] = true;
	vowel_map['E'] = true;
	vowel_map['I'] = true;
	vowel_map['O'] = true;
	vowel_map['U'] = true;

	for (int i = 0; i < s.size(); i++) {
		if (vowel_map[s[i]]) {
			vowel_string += s[i];
		}
	}
	std::sort(vowel_string.begin(), vowel_string.end());
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (vowel_map[s[i]]) {
			s[i] = vowel_string[idx];
			idx++;
		}
	}

	return s;
}
};
