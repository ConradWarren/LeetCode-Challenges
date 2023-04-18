#include <string>

class Solution {
public:
std::string mergeAlternately(std::string word1, std::string word2) {

	int idx_1 = 0;
	int idx_2 = 0;
	std::string merged_words;

	while (idx_1 < word1.length() && idx_2 < word2.length()) {
		merged_words += word1[idx_1];
		merged_words += word2[idx_2];
		idx_1++;
		idx_2++;
	}

	while (idx_1 < word1.length()) {
		merged_words += word1[idx_1];
		idx_1++;
	}

	while (idx_2 < word2.length()) {
		merged_words += word2[idx_2];
		idx_2++;
	}

	return merged_words;
}
};
