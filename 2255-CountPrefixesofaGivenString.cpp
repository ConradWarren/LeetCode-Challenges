#include <string>
#include <vector>

class Solution {
public:
int countPrefixes(std::vector<std::string>& words, std::string s) {

	int result = 0;
	for (int i = 0; i < words.size(); i++) {
		if (s.substr(0, words[i].length()) == words[i]) {
			result++;
		}
	}

	return result;
}
};
