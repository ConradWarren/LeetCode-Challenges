#include <string>

class Solution {
public:
std::string reversePrefix(std::string word, char ch) {

	
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == ch) {
			std::reverse(word.begin(), word.begin() + i+1);
			break;
		}
	}

	return word;
}
};
