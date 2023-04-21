#include <string>

class Solution {
public:
std::string reverseVowels(std::string s) {

	std::string vowle_key = "aeiouAEIOU";
	std::string found_vowles;
	std::string result;

	for (int i = 0; i < s.length(); i++) {
		auto It = std::find(vowle_key.begin(), vowle_key.end(), s[i]);
		if (It != vowle_key.end()) {
			found_vowles += s[i];
		}
	}

	std::reverse(found_vowles.begin(), found_vowles.end());
	int idx = 0;

	for (int i = 0; i < s.length(); i++) {
		auto It = std::find(vowle_key.begin(), vowle_key.end(), s[i]);
		if (It != vowle_key.end()) {
			result += found_vowles[idx];
			idx++;
		}
		else {
			result += s[i];
		}
	}

	return result;
}
};
